/*
 * Console.cpp
 *
 *  Created on: 04.11.2025
 *      Author: Admin
 */

#include "Console.h"

Console::Console()
{
	// TODO Auto-generated constructor stub

}

Console::~Console()
{
	// TODO Auto-generated destructor stub
}

void Console::print(const Board& board) const
{
	int boardSize = board.getSize();
	//Print the col index line
	cout << "   ";
	for(int x = 0; x<boardSize; x++){
		cout << x << "   ";
	}
	cout << endl;
	string state;
	for(int x = 0; x<boardSize; x++){
		//Print row by row
		for(int y = 0; y<boardSize; y++){
			//Print the row index at the start of a new line
			if(y==0){
				cout << x << "  ";
			}
			//Get the value of that cell and print corresponding symbol
			Mark fieldValue = board.getBoard()[x][y];
			switch (fieldValue) {
				case Mark::Empty: state = "."; break;
				case Mark::X: state = "X"; break;
				case Mark::O: state = "O"; break;
			}
			cout << state << "   ";
		}
		cout  << endl;
		cout  << endl;
	}
}
