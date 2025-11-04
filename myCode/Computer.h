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
	Cell getNextMove(const vector<vector<Mark>>& board, Mark mark);
	Cell findRandomValidMove(const vector<vector<Mark>>& board, Mark mark);
};

#endif /* COMPUTER_H_ */
