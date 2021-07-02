#pragma once

/**
* Abstract class for Artificial Intelligence
*/

#include "gameparams.h"

namespace TTTGame
{
	class TicTacToeAI {
	public:
		virtual int Next(const STATE* field, size_t size, STATE move) = 0;
	};
};
