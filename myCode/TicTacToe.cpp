/*
 * TicTacToe.cpp
 *
 *  Created on: 01.11.2025
 *      Author: Admin
 */

#include "TicTacToe.h"

TicTacToe::	TicTacToe(int boardSize, Screen* screen)
{
	if(boardSize >2 ) m_boardSize = boardSize;
	else{
		m_boardSize = 3;
		std::cout << "The given size is not valid. A board size 3 is "
				"chosen automatically" << endl<< endl;
	}

	//Initialize the 2d vector with Empty
	m_board = vector<vector<Mark>>(m_boardSize,vector<Mark>(m_boardSize, Mark::Empty));

	m_screen = screen;
}

TicTacToe::~TicTacToe()
{
	// TODO Auto-generated destructor stub
}

void TicTacToe::play()
{
//	initPlayers();
	m_players[0] = make_unique<Human>(Mark::X);
	m_players[1] = make_unique<Human>(Mark::O);
	for (unsigned short i = 0; i < m_boardSize*m_boardSize; i++)
	{
		Mark mark = Mark::Empty;
		cout << "Placing a stone in round " << i+1 << endl;
		if(i%2 == 0) mark = Mark::O;
		else mark = Mark::X;

		Cell nextMove = m_players[i%2]->getNextMove(m_board, mark);

		while(!isCellValid(nextMove)){
			cout << "Move is invalid, redo" << endl;
			Cell nextMove = m_players[i%2]->getNextMove(m_board, mark);

		}
		bool finished = addMoveCheckWin(nextMove, mark);
		m_screen->print(m_board, m_boardSize);
		if (finished)
		{
			cout << "We have a winner!!!" << endl;
			return; //hacky break
		}
	}
	cout << "Draw...." << endl;
}

bool TicTacToe::isCellValid(const Cell& c) const{
	if (0> c.getRow() || m_boardSize-1 < c.getRow() ){
		return false;
	} else if (0> c.getCol() || m_boardSize-1 < c.getCol() ){
		return false;
	} else if (m_board[c.getRow()][c.getCol()] != Mark::Empty){
		return false;
	}
	return true;
}

void TicTacToe::initPlayers() {
    int choice=1;
    std::cout << "Player 1 (1=Human, 2=Computer): ";
    std::cin >> choice;

    if (choice == 1)
        m_players[0] = make_unique<Human>(Mark::X);
    else
        m_players[0] = make_unique<Computer>(Mark::X);

    std::cout << "Player 2 (1=Human, 2=Computer): ";
    std::cin >> choice;

    if (choice == 1)
        m_players[1] = make_unique<Human>(Mark::O);
    else
        m_players[1] = make_unique<Computer>(Mark::O);
}

bool TicTacToe::addMoveCheckWin(const Cell &c, Mark mark)
{
	m_board[c.getRow()][c.getCol()] = mark;

	//checck vertical, horizontal and diagonal aka 4 direction from this point
	return false;
}
