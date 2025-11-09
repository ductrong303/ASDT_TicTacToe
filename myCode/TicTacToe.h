/*
 * TicTacToe.h
 *
 *  Created on: 01.11.2025
 *      Author: Admin
 */

#ifndef TICTACTOE_H_
#define TICTACTOE_H_
#include "Player.h"
#include "Human.h"
#include "Screen.h"
#include "Computer.h"
#include <memory>
#include <iostream>
#include "Board.h"
using namespace std;


class TicTacToe
{
private:
	unique_ptr<Player> m_players[2];
	Board m_board;
	Screen* m_screen;

public:
	TicTacToe(int boardSize, Screen* screen);
	virtual ~TicTacToe();
	void play();
//	bool isCellValid(const Cell& c) const;
	void initPlayers();
//	bool addMoveCheckWin(const Cell& c, Mark mark);

//	void createPlayer(PlayerType player);
};

#endif /* TICTACTOE_H_ */
