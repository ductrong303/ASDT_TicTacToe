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
protected:
public:
	Player();
	virtual ~Player();
	virtual Cell getNextMove(const vector<vector<CellState>>& board, CellState mark)=0;

};

#endif /* PLAYER_H_ */
