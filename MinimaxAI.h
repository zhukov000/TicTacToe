#pragma once

#include "TicTacToeAI.h"
#include "GameBasic.h"

#include <unordered_map>

/**
* MinMax
* 
* Principals of solve using decision tree
* 
* 1) Every list: +1 (AI win), -1 (AI lose), 0 (tie)
* 2) For even depth (after player move): select max rate from children nodes
* 3) For odd depth (after AI move): select min rate from children nodes
*/

namespace TTTGame
{
	using TKey = uint64_t;

	class MinimaxAI : public TicTacToeAI
	{
	public:
		virtual int Next(const STATE* field, size_t size, STATE move) override;
		virtual ~MinimaxAI();
	
	private:
		// pack field array to key
		TKey fieldToKey(const STATE* field, size_t size);
		
		// unpack key to field array
		STATE* keyToField(TKey key, size_t size);
		
		/// <summary>
		/// 
		/// </summary>
		/// <param name="field"></param>
		/// <param name="size"></param>
		/// <param name="stepAI">1 if next move AI, 0 if next move player</param>
		/// <param name="moveAI">CROSS or ZERO</param>
		/// <param name="stepsLeft"></param>
		/// <returns></returns>
		int8_t rate(STATE* field, size_t size, size_t stepAI, STATE moveAI, size_t stepsLeft);
		
		std::unordered_map<TKey, int8_t> cache;
	};
}


