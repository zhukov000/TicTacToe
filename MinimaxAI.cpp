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
	// TODO: gready logic
	return Move(j); // save last move;
}
