#pragma once

#include "RandomAI.h"
#include "GameBasic.h" 

namespace TTTGame
{
	class Game
	{
	public:
		Game(size_t pSize=3, bool pPlayerFirst=false, TicTacToeAI* pAI = new RandomAI());
		virtual ~Game();

		// return false, if invalid move
		bool playerMove(size_t pY, size_t pX);

		// 0 - no, 1 - first, 2 - second
		size_t Winner();
		
		//
		std::pair<size_t, size_t> lastAiMove();

		// return true if player moved first
		inline bool isPlayerFirst() { return playerFirst; }

		// return true if game was stopped
		inline bool isGameStopped() { return gameStop == 0; }
		// 
		inline size_t Size() { return size; }

	protected:
		// change field state for players
		void move(size_t pY, size_t pX, bool first);

		// get winner for game
		STATE getWinner();

	private:
		void aiMove();

		TicTacToeAI* ai;
		STATE* field;
		size_t size;
		bool playerFirst;
		int gameStop;
		STATE winner;
	};

	class GameStopException : public std::exception {
		const char* what() const throw () {
			return "The game was stopped. The move was not possible";
		}
	};
};

