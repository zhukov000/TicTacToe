#include "Game.h"

using namespace TTTGame;

Game::Game(size_t pSize, bool pPlayerFirst, TicTacToeAI* pAI): ai(pAI) {
	field = new STATE[pSize * pSize];
	size = pSize;

	for (int i = 0; i < size * size; ++i) {
		field[i] = EMPTY;
	}

	playerFirst = pPlayerFirst;
	gameStop = size * size;
	winner = EMPTY;

	if (!playerFirst) {
		aiMove();
	}
}

Game::~Game() {
	delete ai;
	delete[] field;
}

bool Game::playerMove(size_t pY, size_t pX) {
	if (pX >= size || pY >= size || gameStop == 0) return false;
	
	size_t j = size * pY + pX;
	if (field[j] != EMPTY) return false;
	
	// player move
	move(pY, pX, playerFirst);

	if (getWinner() == EMPTY) { // AI answer
		aiMove();
	}

	return true;
}

void Game::aiMove() {
	size_t j = ai->Next(field, size, (!playerFirst ? CROSS : ZERO));
	size_t Y = j / size;
	size_t X = j % size;

	move(Y, X, !playerFirst);
	getWinner();
}

std::pair<size_t, size_t> Game::lastAiMove() {
	size_t j = ai->Last();
	return { j / size, j % size };
}

void Game::move(size_t pY, size_t pX, bool first) {
	if (gameStop == 0) {
		// throw GameStopException();
		return;
	}

	field[size * pY + pX] = (first ? CROSS : ZERO);
	gameStop--;
}

STATE Game::getWinner() {
	if (winner == EMPTY) {
		winner = GameBasic::checkWinner(field, size);
	}
	if (winner != EMPTY) {
		gameStop = 0;
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