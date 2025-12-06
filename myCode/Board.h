/*
 * Board.h
 *
 *  Created on: 6 Nov 2025
 *      Author: ductr
 */

/**
 * @file Board.h
 * @brief Declaration of the Board class that stores and manages the game grid.
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <vector>
using namespace std;
#include "Cell.h"
#include <iostream>
using namespace std;
#include <algorithm>

/**
 * @class Board
 * @brief Represents a 2D tic-tac-toe board and provides operations on it.
 */
class Board
{
private:
    /**
     * @brief 2D matrix of marks representing the current board state.
     */
	vector<std::vector<Mark>> m_board;

    /**
     * @brief Size of one side of the square board.
     */
	int m_boardSize;

public:
    /**
     * @brief Constructs a board with the given size.
     * @param boardSize Length of one side of the square board.
     */
	Board(int boardSize);

    /**
     * @brief Copy constructor performing a deep copy of the board state.
     * @param orig Board instance to copy.
     */
	Board(const Board& orig);

    /**
     * @brief Copy constructor performing a deep copy of the board state.
     * @param orig Board instance to copy.
     */
	virtual ~Board();

    /**
     * @brief Checks if the last move at the given cell caused a win.
     * @param c Cell in which the last move was placed.
     * @return True if a winning line is found, otherwise false.
     */
	bool checkWin(const Cell& c);

    /**
     * @brief Places a mark at the given cell coordinates.
     * @param c Target cell position.
     * @param mark Mark to be placed.
     */
	void addMove(const Cell& c, Mark mark);

    /**
     * @brief Validates if a move to the given cell is allowed.
     * @param c Cell to be checked.
     * @return True if the cell is inside the board and empty, otherwise false.
     */
	bool isCellValid(const Cell& c) const;

    /**
     * @brief Provides read-only access to the internal board matrix.
     * @return Constant reference to the 2D vector of marks.
     */
	const vector<std::vector<Mark>>& getBoard() const;

    /**
     * @brief Obtains the size of one side of the board.
     * @return Board size as an integer.
     */
	int getSize() const;

    /**
     * @brief Checks if there is at least one empty cell left on the board.
     * @return True if a move is still possible, otherwise false.
     */
	bool isMoveLeft() const;

    /**
     * @brief Checks if a given row contains a winning line.
     * @param row Row index to check.
     * @return True if all cells in the row contain the same non-empty mark.
     */
	bool checkRowForVictory(int row) const;

    /**
     * @brief Checks if a given column contains a winning line.
     * @param col Column index to check.
     * @return True if all cells in the column contain the same non-empty mark.
     */
	bool checkColForVictory(int col) const;

    /**
     * @brief Checks if any diagonal contains a winning line.
     * @return True if one of the diagonals contains the same non-empty mark.
     */
	bool checkDiagonalsForVictory() const;

    /**
     * @brief Returns the mark stored at the given cell.
     * @param c Target cell.
     * @return Mark at the given position.
     */
	Mark getCellValue(const Cell& c) const;
};

#endif /* BOARD_H_ */
