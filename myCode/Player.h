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
using namespace std;

enum class PlayerType{
	Human, Computer
};

class Player
{
private:
	Mark m_mark;
public:
	Player(Mark mark);
	virtual ~Player();
	virtual Cell getNextMove(const vector<vector<Mark>>& board, Mark mark)=0;

};

#endif /* PLAYER_H_ */
