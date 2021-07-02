#pragma once

#include "TicTacToeAI.h"
#include "Tools.h"

namespace TTTGame
{
	class RandomAI: public TicTacToeAI {
	public:
		int Next(const STATE* field, size_t size, STATE move) override;
		virtual ~RandomAI();
	};
};