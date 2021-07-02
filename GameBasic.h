#pragma once

/**
* Defines TicTacToe basic winner check
*/

#include "gameparams.h"

namespace TTTGame
{
	class GameBasic
	{
	public:
		// return winner code or EMPTY
		static STATE checkWinner(const STATE* field, const size_t& size);

		// check winner for define state
		static bool checkState(const STATE* field, const size_t& size, STATE st);
	};
}

