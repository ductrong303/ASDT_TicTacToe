/*
 * Player.cpp
 *
 *  Created on: 01.11.2025
 *      Author: Admin
 */

#include "Player.h"

Player::Player(Mark mark)
{
	m_mark = mark;
}

Player::~Player()
{
	// TODO Auto-generated destructor stub
}

Mark Player::getMark() const
{
	return m_mark;
}

Mark Player::getOpponentMark() const
{
	if(m_mark == Mark::X) return Mark::O;
	else return Mark::X;
}
