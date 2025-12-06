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
	//Choosing players
	initPlayers();
	//Print start board
	m_screen->print(m_board);
	//Main loop
	for (unsigned short i = 0; i < m_board.getSize()*m_board.getSize(); i++)
	{
		//Get move from the player in turn
		cout << "Placing a stone in round " << i+1 << endl;
		Mark current_mark = m_players[i%2]->getMark();
		Cell nextMove = m_players[i%2]->getNextMove(m_board);

		//Re-choose till move is valid
		while(!m_board.isCellValid(nextMove)){
			cout << "Move is invalid, redo" << endl;
			nextMove = m_players[i%2]->getNextMove(m_board);
		}

		//Move is valid, add to the map
		m_board.addMove(nextMove, current_mark);
		//Check win
		bool finished = m_board.checkWin(nextMove);
		//Update screen
		m_screen->print(m_board);
		//If game ends
		if (finished)
		{
			cout << "We have a winner!!!" << endl;
			return; //hacky break
		}
	}
	//No cells left, game ends
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
