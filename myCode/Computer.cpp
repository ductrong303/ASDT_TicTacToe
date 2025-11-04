/*
 * Computer.cpp
 *
 *  Created on: 01.11.2025
 *      Author: Admin
 */

#include "Computer.h"
#include <cstdlib> // rand, srand

Computer::Computer(Mark mark):Player(mark)
{
	// TODO Auto-generated constructor stub

}

Computer::~Computer()
{
	// TODO Auto-generated destructor stub
}

Cell Computer::getNextMove(const vector<vector<Mark> > &board, Mark mark)
{
	cout << "Computer get sth random" << endl;
	int row = rand()%3;
	int col = rand()%3;

	return Cell(row, col);
}

