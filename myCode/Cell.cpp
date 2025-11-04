/*
 * Cell.cpp
 *
 *  Created on: 3 Nov 2025
 *      Author: ductr
 */

#include "Cell.h"

Cell::Cell(int row, int col)
{
	m_row = row;
	m_col = col;

}

Cell::~Cell()
{
	// TODO Auto-generated destructor stub
}

int Cell::getRow() const
{
	return m_row;
}

int Cell::getCol() const
{
	return m_col;
}
