#include "GameBasic.h"

using namespace TTTGame;

STATE GameBasic::checkWinner(const STATE* field, const size_t& size) {
	if (checkState(field, size, STATE::CROSS)) {
		return STATE::CROSS;
	}
	if (checkState(field, size, STATE::ZERO)) {
		return STATE::ZERO;
	}
	return STATE::EMPTY;
}

bool GameBasic::checkState(const STATE* field, const size_t& size, STATE st) {
	bool diag1 = true;
	bool diag2 = true;

	for (size_t i = 0; i < size; ++i) {
		bool allInRow = true;
		bool allInCol = true;
		for (size_t j = 0; j < size; ++j) {
			if (field[i * size + j] != st) {
				allInRow = false;
			}
			if (field[j * size + i] != st) {
				allInCol = false;
			}
		}

		if (allInRow || allInCol) return true;

		if (field[i * size + i] != st) {
			diag1 = false;
		}
		if (field[i * size + (size - 1 - i)] != st) {
			diag2 = false;
		}
	}
	return (diag1 || diag2);
}