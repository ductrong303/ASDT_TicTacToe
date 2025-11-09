/*
 * Cell.h
 *
 *  Created on: 3 Nov 2025
 *      Author: ductr
 */

#ifndef CELL_H_
#define CELL_H_

enum class Mark{
	X, O, Empty
};


class Cell
{
private:
	int m_row;
	int m_col;
public:
	Cell(int row, int col);
	virtual ~Cell();
	int getRow() const;
	int getCol() const;

	void setCol(int col)
	{
		m_col = col;
	}

	void setRow(int row)
	{
		m_row = row;
	}
};

#endif /* CELL_H_ */
