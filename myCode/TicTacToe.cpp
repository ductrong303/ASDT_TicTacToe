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

    // set the empty state for all fields
    for(int x = 0; x<m_boardSize; x++){
    	for(int y = 0; y<m_boardSize; y++){
    		m_board[x][y]= CellState::Empty;
    	}
    }
	m_screen = screen;
}

TicTacToe::~TicTacToe()
{
	// TODO Auto-generated destructor stub
}

void TicTacToe::play()
{
	initPlayers();
	for (unsigned short i = 0; i < m_boardSize*m_boardSize; i++)
	{
		CellState mark = CellState::Empty;
		cout << "Placing a stone in round " << i+1 << endl;
		if(i%2 == 0) mark = CellState::O;
		else mark = CellState::X;
		Cell nextMove(-1, -1);
		do{
			nextMove = m_players[i%2]->getNextMove(m_board, mark);
		}while (isCellValid(nextMove));
		bool finished = placeMoveCheckWin(nextMove, mark);
//		m_screen->print();
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
	} else if (m_board[c.getRow()][c.getCol()] != CellState::Empty){
		return false;
	}
	return true;
}

void TicTacToe::initPlayers() {
    int choice;
    std::cout << "Player 1 (1=Human, 2=Computer): ";
    std::cin >> choice;

    if (choice == 1)
        m_players[0] = make_unique<Human>();
    else
        m_players[0] = make_unique<Computer>();

    std::cout << "Player 2 (1=Human, 2=Computer): ";
    std::cin >> choice;

    if (choice == 1)
        m_players[1] = make_unique<Human>();
    else
        m_players[1] = make_unique<Computer>();
}

bool TicTacToe::placeMoveCheckWin(const Cell &c, CellState mark)
{
	m_board[c.getRow()][c.getCol()] = mark;

	//checck vertical, horizontal and diagonal aka 4 direction from this point
	return true;
}
