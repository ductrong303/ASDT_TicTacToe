/*
 * Cell.h
 *
 *  Created on: 3 Nov 2025
 *      Author: ductr
 */

/**
 * @file Cell.h
 * @brief Declaration of the Cell class representing a board position.
 */

#ifndef CELL_H_
#define CELL_H_

/**
 * @enum Mark
 * @brief Possible states of a board cell.
 */
enum class Mark{
	X, O, Empty
};

/**
 * @class Cell
 * @brief Represents a single cell on the game board, identified by row and column indices.
 */
class Cell
{
private:
    /**
     * @brief Row index of the cell on the board.
     */
	int m_row;

	/**
	 * @brief Column index of the cell on the board.
	 */
	int m_col;
public:
    /**
     * @brief Constructs a cell with the given row and column.
     * @param row Zero-based row index.
     * @param col Zero-based column index.
     */
	Cell(int row, int col);

    /**
     * @brief Constructs a cell with the given row and column.
     * @param row Zero-based row index.
     * @param col Zero-based column index.
     */
	virtual ~Cell();

    /**
     * @brief Constructs a cell with the given row and column.
     * @param row Zero-based row index.
     * @param col Zero-based column index.
     */
	int getRow() const;

    /**
     * @brief Gets the column index of the cell.
     * @return The zero-based column index.
     */
	int getCol() const;

    /**
     * @brief Sets the column index of the cell.
     * @param col New zero-based column index.
     */
	void setCol(int col)
	{
		m_col = col;
	}

    /**
     * @brief Sets the column index of the cell.
     * @param col New zero-based column index.
     */
	void setRow(int row)
	{
		m_row = row;
	}
};

#endif /* CELL_H_ */
