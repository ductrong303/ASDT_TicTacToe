/*
 * Human.h
 *
 *  Created on: 01.11.2025
 *      Author: Admin
 */

#ifndef HUMAN_H_
#define HUMAN_H_

#include "Player.h"

class Human: public Player
{
public:
	Human();
	virtual ~Human();
	Cell getNextMove(const vector<vector<CellState>>& board, CellState mark);
};

#endif /* HUMAN_H_ */
