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
	Human(Mark mark);
	virtual ~Human();
	Cell getNextMove(const Board& board);
};

#endif /* HUMAN_H_ */
