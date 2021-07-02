#include "RandomAI.h"

TTTGame::RandomAI::~RandomAI() {
	// do nothing
}

int TTTGame::RandomAI::Next(const STATE* field, size_t size, STATE move) {
	size_t cntEmpty = 0;
	for (size_t i = 0; i < size; ++i) {
		if (field[i] == STATE::EMPTY) {
			cntEmpty++;
		}
	}
	if (cntEmpty == 0) return -1;
	
	size_t j = Rnd::genInt(1, cntEmpty);
	for (size_t i = 0; i < size; ++i) {
		if (field[i] == STATE::EMPTY) {
			j--;
			if (j == 0) {
				return static_cast<int>(i);
			}
		}
	}
}
