/*
 * Computer.h
 *
 *  Created on: 01.11.2025
 *      Author: Admin
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_

#include "Player.h"

class Computer: public Player
{
public:
	Computer(Mark mark);
	virtual ~Computer();
	Cell getNextMove(const Board& board);
	Cell findRandomValidMove(const Board& board);
	int returnScore(int depth);
	int applyMiniMax(Board& board, int depth, bool isMax);
	int evaluateBoard(const Board& board);
	Cell findBestMove(Board& board);
};

#endif /* COMPUTER_H_ */
