/*
 * TicTacToe.cpp
 *
 *  Created on: 01.11.2025
 *      Author: Admin
 */

#include "TicTacToe.h"

TicTacToe::	TicTacToe(int boardSize, Screen* screen):m_board(boardSize), m_screen(screen)
{

}

TicTacToe::~TicTacToe()
{
	// TODO Auto-generated destructor stub
}

void TicTacToe::play()
{
//	initPlayers();
	m_players[1] = make_unique<Human>(Mark::X);
	m_players[0] = make_unique<Computer>(Mark::O);
	m_screen->print(m_board);
	for (unsigned short i = 0; i < m_board.getSize()*m_board.getSize(); i++)
	{
		cout << "Placing a stone in round " << i+1 << endl;
//		if(i%2 == 0) mark = Mark::O;
//		else mark = Mark::X;
		Mark current_mark = m_players[i%2]->getMark();
		Cell nextMove = m_players[i%2]->getNextMove(m_board);

		while(!m_board.isCellValid(nextMove)){
			cout << "Move is invalid, redo" << endl;
			nextMove = m_players[i%2]->getNextMove(m_board);

		}
		m_board.addMove(nextMove, current_mark);
		bool finished = m_board.checkWin(nextMove);
		m_screen->print(m_board);
		if (finished)
		{
			cout << "We have a winner!!!" << endl;
			return; //hacky break
		}
	}
	cout << "Draw...." << endl;
}


void TicTacToe::initPlayers() {
    int choice=2;
    cout << "Player 1 (1=Human, 2=Computer): ";
    cin >> choice;

    if (choice == 1)
        m_players[0] = make_unique<Human>(Mark::X);
    else
        m_players[0] = make_unique<Computer>(Mark::X);

    cout << "Player 2 (1=Human, 2=Computer): ";
    cin >> choice;

    if (choice == 1)
        m_players[1] = make_unique<Human>(Mark::O);
    else
        m_players[1] = make_unique<Computer>(Mark::O);
}
