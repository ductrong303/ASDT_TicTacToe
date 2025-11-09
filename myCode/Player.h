/*
 * Player.h
 *
 *  Created on: 01.11.2025
 *      Author: Admin
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include <vector>
#include <iostream>
#include "Cell.h"
#include "Board.h"
using namespace std;

enum class PlayerType{
	Human, Computer
};

class Player
{
protected:
	Mark m_mark;
public:
	Player(Mark mark);
	virtual ~Player();
	virtual Cell getNextMove(const Board& board)=0;
	Mark getMark() const;
	Mark getOpponentMark() const;

};

#endif /* PLAYER_H_ */
