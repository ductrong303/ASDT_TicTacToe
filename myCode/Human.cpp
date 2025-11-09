/*
 * Human.cpp
 *
 *  Created on: 01.11.2025
 *      Author: Admin
 */

#include "Human.h"

Human::Human(Mark mark):Player(mark)
{
	// TODO Auto-generated constructor stub

}

Human::~Human()
{
	// TODO Auto-generated destructor stub
}


Cell Human::getNextMove(const Board& board)
{
	//Ask for user Input of x and y coordinator
	//Create Cell for that state
	int row, col;
	cout<< "Insert the cell you want to play"<< endl;
	cout << "Row: " ;
	cin >> row;
	cout << "Col: ";
	cin >> col;
	return Cell(row, col);
}
