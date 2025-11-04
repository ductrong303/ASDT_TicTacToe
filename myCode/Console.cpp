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

void Console::print(const vector<vector<Mark> > &board, int boardSize) const
{
	cout << "	";
	for(int x = 0; x<boardSize; x++){
		std::cout << x << "	";
	}
	std::cout  << std::endl;
	std::string state;
	for(int x = 0; x<boardSize; x++){
		for(int y = 0; y<boardSize; y++){
			if(y==0){
				std::cout << x << "	";
			}

//			if(board[x][y]==Mark::Empty){
//						state = ".";
//			}
//			else{
			Mark fieldValue = board[x][y];
			switch (fieldValue) {
				case Mark::Empty: state = "."; break;
				case Mark::X: state = "X"; break;
				case Mark::O: state = "O"; break;
//			    }
			}
			std::cout << state << "	";
		}
		std::cout  << std::endl;
		std::cout  << std::endl;
	}
}
