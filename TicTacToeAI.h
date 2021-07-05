#pragma once

/**
* Abstract class for Artificial Intelligence
*/

#include "gameparams.h"
#include <vector>

namespace TTTGame
{
	class TicTacToeAI {
	public:
		virtual int Next(const STATE* field, size_t size, STATE move) = 0;
		inline size_t Last() { return moves.back(); };

	protected:
		int Move(size_t i);
	
	private:
		std::vector<size_t> moves;
	};
};
