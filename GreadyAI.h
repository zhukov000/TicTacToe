#pragma once

#include "TicTacToeAI.h"
#include "GameBasic.h"

/**
*	 Gready logic - choose the first available move from the following list:
* 1) Win: If the player has two in a row, they can place a third to get three in a row.
* 2) Block: If the opponent has two in a row, the player must play the third themselves to block the opponent.
* 3) Fork: Create an opportunity where the player has two ways to win (two non-blocked lines of 2).
* 4) Blocking an opponent's fork: If there is only one possible fork for the opponent, the player should block it. 
	 Otherwise, the player should block all forks in any way that simultaneously allows them to create 
	 two in a row. 
* 5) Center: A player marks the center. (If it is the first move of the game, playing a corner move gives the second player more opportunities to make a mistake and may therefore be the better choice; however, it makes no difference between perfect players.)
* 6) Opposite corner: If the opponent is in the corner, the player plays the opposite corner.
* 7) Empty corner: The player plays in a corner square.
* 8) Last empty
*/

namespace TTTGame
{
	class GreadyAI : public TicTacToeAI
	{
	public:
		virtual int Next(const STATE* field, size_t size, STATE move) override;
		virtual ~GreadyAI();

	private:
		// Win: check size-1 in row
		size_t greadyWinMove(const STATE* field, size_t size, STATE move);

		// Fork: check position for create fork
		size_t greadyForkMove(const STATE* field, size_t size, STATE move);

		// count possible forks
		size_t countForks(const STATE* field, size_t size, STATE move);

		// find position blocked all possible forks
		size_t blockForks(const STATE* field, size_t size, STATE move);
	};
}

