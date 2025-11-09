/*
 * Board.cpp
 *
 *  Created on: 6 Nov 2025
 *      Author: ductr
 */

#include "Board.h"

Board::Board(int boardSize)
{
	m_boardSize = boardSize;
	m_board = vector<vector<Mark>>(m_boardSize,vector<Mark>(m_boardSize, Mark::Empty));
}

Board::~Board()
{
	// TODO Auto-generated destructor stub
}

bool Board::checkWin(const Cell &c)
{
	int row = c.getRow();
	int col = c.getCol();
	//Check row with placed Mark
	if(m_board[row][0] == m_board[row][1] && m_board[row][1] == m_board[row][2]){
		cout << "Three on a row"<< endl;
		return true;
	}
	//Check col with placed Mark
	if(m_board[0][col] == m_board[1][col] && m_board[1][col] == m_board[2][col]){
		cout << "Three on a column"<< endl;
		return true;
	}
	//Check the two diagonal lines
	if(m_board[0][0] == m_board[1][1] && m_board[1][1] == m_board[2][2] && m_board[1][1]!= Mark::Empty){
		cout << "Three on a diagonal"<< endl;
		return true;
	}
	if(m_board[0][2] == m_board[1][1] && m_board[1][1] == m_board[2][0] && m_board[1][1]!= Mark::Empty){
		cout << "Three on a diagonal"<< endl;
		return true;
	}
	return false;
}

bool Board::isCellValid(const Cell& c) const{
	if (0> c.getRow() || m_boardSize-1 < c.getRow() ){
		return false;
	} else if (0> c.getCol() || m_boardSize-1 < c.getCol() ){
		return false;
	} else if (m_board[c.getRow()][c.getCol()] != Mark::Empty){
		return false;
	}
	return true;
}

const vector<std::vector<Mark>>& Board::getBoard() const
{
	return m_board;
}

void Board::addMove(const Cell &c, Mark mark)
{
	m_board[c.getRow()][c.getCol()] = mark;
}

int Board::getSize() const
{
	return m_boardSize;
}

bool Board::isMoveLeft() const
{
	for(auto& row:m_board){
		if(find(row.begin(), row.end(), Mark::Empty) != row.end()){
			return true;
		}
	}
	return false;
}

bool Board::checkRowForVictory(int row) const
{
	if(m_board[row][0] == m_board[row][1] && m_board[row][1] == m_board[row][2]&& m_board[row][0]!= Mark::Empty){
		return true;
	}
	return false;
}

bool Board::checkColForVictory(int col) const
{
	if(m_board[0][col] == m_board[1][col] && m_board[1][col] == m_board[2][col] && m_board[0][col] != Mark::Empty){
		return true;
	}
	return false;
}

bool Board::checkDiagonalsForVictory() const
{
	if(m_board[0][0] == m_board[1][1] && m_board[1][1] == m_board[2][2] && m_board[1][1]!= Mark::Empty){
		return true;
	}
	if(m_board[0][2] == m_board[1][1] && m_board[1][1] == m_board[2][0] && m_board[1][1]!= Mark::Empty){
		return true;
	}
	return false;
}

Board::Board(const Board& orig)
{
    m_boardSize = orig.m_boardSize;
    m_board = orig.m_board; // std::vector handles deep copy automatically
}

Mark Board::getCellValue(const Cell &c) const
{
	return m_board[c.getRow()][c.getCol()];
}
