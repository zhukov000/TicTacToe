#include "TicTacToeAI.h"

int TTTGame::TicTacToeAI::Move(size_t i) {
	moves.push_back(i); 
	return static_cast<int>(i);
}