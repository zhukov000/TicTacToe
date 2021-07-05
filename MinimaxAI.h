#pragma once

#include "TicTacToeAI.h"
#include "GameBasic.h"

namespace TTTGame
{
	class MinimaxAI : public TicTacToeAI
	{
		virtual int Next(const STATE* field, size_t size, STATE move) override;
		virtual ~MinimaxAI();
	};
}


