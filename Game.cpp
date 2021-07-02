#include "Game.h"

using namespace TTTGame;

Game::Game(size_t pSize, bool pPlayerFirst, TicTacToeAI* pAI): ai(pAI) {
	field = new STATE[pSize * pSize];
	size = pSize;
	playerFirst = pPlayerFirst;
	gameStop = false;
	winner = EMPTY;
}

Game::~Game() {
	delete ai;
	delete[] field;
}

bool Game::playerMove(size_t pY, size_t pX) {
	if (pX >= size || pY >= size || gameStop) return false;
	
	size_t j = size * pY + pX;
	if (field[j] != EMPTY) return false;
	
	// player move
	move(pY, pX, playerFirst);

	if (getWinner() != EMPTY) {
		// AI answer
		size_t j = ai->Next(field, size, (!playerFirst ? CROSS : ZERO));
		size_t Y = j / size;
		size_t X = j % size;

		move(Y, X, !playerFirst);
		getWinner();
	}

	return true;
}

void Game::move(size_t pY, size_t pX, bool first) {
	if (gameStop) {
		throw GameStopException();
	}

	field[size * pY + pX] = (first ? CROSS : ZERO);
}

STATE Game::getWinner() {
	if (winner == EMPTY) {
		winner = GameBasic::checkWinner(field, size);
	}
	if (winner != EMPTY) {
		gameStop = true;
	}
	return winner;
}

size_t Game::Winner() {
	if (winner == EMPTY) {
		return 0;
	}
	else if (winner == CROSS) {
		return 1;
	}
	return 2;
}