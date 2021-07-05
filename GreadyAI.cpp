#include "GreadyAI.h"

TTTGame::GreadyAI::~GreadyAI() {
	// do nothing
}

size_t TTTGame::GreadyAI::greadyWinMove(const STATE* field, size_t size, STATE move) {
	
	size_t diag1Cnt, diag2Cnt;
	diag1Cnt = diag2Cnt = 0;

	size_t diag1, diag2;
	diag2 = diag1 = size;

	for (size_t i = 0; i < size; ++i) {
		size_t iCol = size;
		size_t iRow = size;

		size_t rowCnt, colCnt;
		rowCnt = colCnt = 0;

		for (size_t j = 0; j < size; ++j) {

			if (field[i * size + j] == move) colCnt++;
			else if (field[i * size + j] == EMPTY) iCol = j;

			if (field[j * size + i] == move) rowCnt++;
			else if (field[j * size + i] == EMPTY) iRow = j;

		}

		if (colCnt + 1 == size && iCol < size) return i * size + iCol;
		if (rowCnt + 1 == size && iRow < size) return iRow * size + i;

		// diag's
		if (field[i * size + i] == move) diag1Cnt++;
		else if (field[i * size + i] == EMPTY) diag1 = i;

		if (field[i * size + size - 1 - i] == move) diag2Cnt++;
		else if (field[i * size + size - 1 - i] == EMPTY) diag2 = i;
	}
	if (diag1Cnt + 1 == size && diag1 != size) return diag1 * size + diag1;
	if (diag2Cnt + 1 == size && diag2 != size) return diag2 * size + size - 1 - diag2;

	return size * size;
}

size_t TTTGame::GreadyAI::greadyForkMove(const STATE* field, size_t size, STATE move) {
	/**
	* Search position:
	* - now is empty
	* - after set we have 2 different strategy for WIN
	*/ 
	size_t result = size * size;
	STATE op_move = (move == CROSS ? ZERO : CROSS);
	STATE* fieldCopy = new STATE[size * size];
	memcpy(fieldCopy, field, size * size * sizeof(STATE));

	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j) {
			size_t forkPos = i * size + j;
			
			if (fieldCopy[forkPos] == EMPTY) {
				fieldCopy[forkPos] = move;
				// check first win
				size_t win1 = greadyWinMove(fieldCopy, size, move);
				if (win1 != size * size) {
					fieldCopy[win1] = op_move;
					size_t win2 = greadyWinMove(fieldCopy, size, move);
					if (win2 != size * size) {
						return forkPos;
					}
					fieldCopy[win1] = EMPTY;
				}
				fieldCopy[forkPos] = EMPTY;
			}
		}
	}

	delete [] fieldCopy;
	return result;
}

size_t TTTGame::GreadyAI::countForks(const STATE* field, size_t size, STATE move) {
	size_t ans = 0;
	
	STATE op_move = (move == CROSS ? ZERO : CROSS);
	STATE* fieldCopy = new STATE[size * size];
	memcpy(fieldCopy, field, size * size * sizeof(STATE));

	size_t fork = greadyForkMove(fieldCopy, size, move);
	if (fork != size * size) {
		fieldCopy[fork] = op_move;
		ans = countForks(fieldCopy, size, move) + 1;
	}

	delete[] fieldCopy;
	return ans;
}

size_t TTTGame::GreadyAI::blockForks(const STATE* field, size_t size, STATE move) {
	STATE op_move = (move == CROSS ? ZERO : CROSS);
	STATE* fieldCopy = new STATE[size * size];
	memcpy(fieldCopy, field, size * size * sizeof(STATE));

	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j) {
			size_t pos = i * size + j;
			if (fieldCopy[pos] == EMPTY) {
				fieldCopy[pos] = move;
				if (countForks(fieldCopy, size, op_move) == 0) {
					return pos;
				}
				fieldCopy[pos] = EMPTY;
			}
		}
	}

	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j) {
			size_t pos = i * size + j;
			if (fieldCopy[pos] == EMPTY) {
				fieldCopy[pos] = move;
				if (greadyWinMove(fieldCopy, size, move) != greadyForkMove(fieldCopy, size, op_move)) {
					return pos;
				}
				fieldCopy[pos] = EMPTY;
			}
		}
	}

	delete[] fieldCopy;
	return size * size;
}

int TTTGame::GreadyAI::Next(const STATE* field, size_t size, STATE move) {
	size_t cntEmpty = 0;
	size_t lastEmpty;
	for (size_t i = 0; i < size * size; ++i) {
		if (field[i] == EMPTY) {
			cntEmpty++;
			lastEmpty = i;
		}
	}
	if (cntEmpty == 0) return -1;
	// opponent move
	STATE op_move = (move == CROSS ? ZERO : CROSS);

	// Win
	{
		size_t win = greadyWinMove(field, size, move);
		if (win != size * size) return Move(win);
	}
	
	// Block
	{
		size_t block = greadyWinMove(field, size, op_move);
		if (block != size * size) return Move(block);
	}
	
	// Fork
	{
		size_t fork = greadyForkMove(field, size, move);
		if (fork != size * size) return Move(fork);
	}
	
	// Block opp's fork
	{
		if (countForks(field, size, op_move) > 1) {
			size_t op_fork = blockForks(field, size, move);
			if (op_fork != size * size) return Move(op_fork);
		}
	
		size_t op_fork = greadyForkMove(field, size, op_move);
		if (op_fork != size * size) return Move(op_fork);
	}
	
	// Center - check 1 or 4 cells
	for (size_t i = 0; i <= 1 - size % 2; ++i) {
		for (size_t j = 0; j <= 1 - size % 2; ++j) {
			size_t mid = (i + (size - 1) / 2) * size + j + (size - 1) / 2;
			if (field[mid] == EMPTY) {
				return Move(mid);
			}
		}
	}
	
	// Opposite corner
	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 2; ++j) {
			size_t corner = i * (size - 1) * size + j * (size - 1);
			size_t op_corner = (1 - i) * (size - 1) * size + (1 - j) * (size - 1);
			if (field[corner] == EMPTY && field[op_corner] == op_move) {
				return Move(corner);
			}
		}
	}
	
	// Empty corner
	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 2; ++j) {
			size_t corner = i * (size - 1) * size + j * (size - 1);
			if (field[corner] == EMPTY) {
				return Move(corner);
			}
		}
	}
	// Last empty field
	return Move(lastEmpty);
}
