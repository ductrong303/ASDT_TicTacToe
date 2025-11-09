/*
 * Board.h
 *
 *  Created on: 6 Nov 2025
 *      Author: ductr
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <vector>
using namespace std;
#include "Cell.h"
#include <iostream>
using namespace std;
#include <algorithm>

class Board
{
private:
	vector<std::vector<Mark>> m_board;
	int m_boardSize;
public:
	Board(int boardSize);
	Board(const Board& orig);
	virtual ~Board();
	bool checkWin(const Cell& c);
	void addMove(const Cell& c, Mark mark);
	bool isCellValid(const Cell& c) const;
	const vector<std::vector<Mark>>& getBoard() const;
	int getSize() const;
	bool isMoveLeft() const;
	bool checkRowForVictory(int row) const;
	bool checkColForVictory(int col) const;
	bool checkDiagonalsForVictory() const;
	Mark getCellValue(const Cell& c) const;
};

#endif /* BOARD_H_ */
