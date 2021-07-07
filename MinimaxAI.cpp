#include "MinimaxAI.h"

TTTGame::MinimaxAI::~MinimaxAI() {
	// do nothing
}

int TTTGame::MinimaxAI::Next(const STATE* field, size_t size, STATE move) {
	size_t cntEmpty = 0;
	size_t j;
	for (size_t i = 0; i < size * size; ++i) {
		if (field[i] == STATE::EMPTY) {
			cntEmpty++;
			j = i;
		}
	}
	if (cntEmpty == 0) return -1;
	
	STATE* fieldCopy = new STATE[size * size];
	memcpy(fieldCopy, field, size * size * sizeof(STATE));

	for (size_t i = 0; i < size * size; ++i) {
		if (field[i] == EMPTY) {
			fieldCopy[i] = move;
			int8_t tr = rate(fieldCopy, size, 0, move, size * size - (move == CROSS ? 1 : 2));
			if (tr >= 0) {
				j = i;
				if (tr == 1) break;
			}
			fieldCopy[i] = EMPTY;
		}
	}

	delete[] fieldCopy;
	return Move(j); // save last move;
}

TTTGame::TKey TTTGame::MinimaxAI::fieldToKey(const STATE* field, size_t size) {
	TKey key = 0;
	for (size_t i = 0; i < size * size; ++i) {
		key <<= 1;
		if (field[i] != EMPTY) key |= 1;
	}
	for (size_t i = 0; i < size * size; ++i) {
		key <<= 1;
		if (field[i] == CROSS) key |= 1;
	}
	return key;
}

TTTGame::STATE* TTTGame::MinimaxAI::keyToField(TKey key, size_t size) {
	STATE* field = new STATE[size * size];
	for (size_t i = size * size; i > 0; --i) {
		field[i - 1] = ( (key & 1) == 1 ? CROSS : ZERO );
		key >>= 1;
	}
	for (size_t i = size * size; i > 0; --i) {
		if ((key & 1) == 0) field[i - 1] = EMPTY;
		key >>= 1;
	}
	return field;
}

// rate of positions
int8_t TTTGame::MinimaxAI::rate(STATE* field, size_t size, size_t stepAI, STATE moveAI, size_t stepsLeft) {
	// player move
	STATE movePlayer = (moveAI == CROSS ? ZERO : CROSS);
	// cache
	STATE st = GameBasic::checkWinner(field, size);
	// get key
	TKey key = fieldToKey(field, size);
	if (cache.count(key) == 0) 
	{
		if (st == EMPTY) {
			if (stepsLeft == 0) {
				cache[key] = 0; // tie
			}
			else {
				int8_t mn = 1, mx = -1;

				for (size_t i = 0; i < size * size; ++i) {
					if (field[i] == EMPTY) {
						field[i] = (stepAI % 2 != 0 ? moveAI : movePlayer);

						int8_t v = rate(field, size, 1 - stepAI, moveAI, stepsLeft - 1);
						if (stepAI % 2 != 0) {
							if (v > mx) mx = v;
						}
						else {
							if (v < mn) mn = v;
						}

						field[i] = EMPTY;
					}
				}
				cache[key] = (stepAI % 2 != 0 ? mx : mn);
			}
		}
		else {
			if (moveAI == st ) {
				cache[key] = 1;
			}	
			else {
				cache[key] = -1;
			}	
		}
	}
	return cache[key];
}