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
/**
 * @file TicTacToe.h
 * @brief Declaration of the TicTacToe game controller class.
 */


using namespace std;

/**
 * @class TicTacToe
 * @brief High-level controller that manages a tic-tac-toe game.
 *
 * The class owns the board and the players, and uses a Screen implementation
 * to display the game progress while running the main game loop.
 */
class TicTacToe
{
private:
    /**
     * @brief Smart pointers to the two players participating in the game.
     */
	unique_ptr<Player> m_players[2];

    /**
     * @brief Game board on which moves are played.
     */
	Board m_board;

    /**
     * @brief Pointer to the screen implementation used for displaying the game.
     */
	Screen* m_screen;

public:
    /**
     * @brief Constructs a game with a given board size and output screen.
     * @param boardSize Size of one side of the square board.
     * @param screen Pointer to the Screen used for rendering the board.
     */
	TicTacToe(int boardSize, Screen* screen);

    /**
     * @brief Virtual destructor.
     */
	virtual ~TicTacToe();

    /**
     * @brief Starts and runs the main game loop until win or draw.
     */
	void play();

    /**
     * @brief Initializes both players (human or computer) based on user selection.
     */
	void initPlayers();
};

#endif /* TICTACTOE_H_ */
