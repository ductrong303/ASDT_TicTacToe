/*
 * Computer.cpp
 *
 *  Created on: 01.11.2025
 *      Author: Admin
 */

#include "Computer.h"
#include <cstdlib> // rand, srand
#include <algorithm>

Computer::Computer(Mark mark):Player(mark)
{

}

Computer::~Computer()
{
}

Cell Computer::getNextMove(const Board& board)
{
	Board boardCopy= board;
	return findBestMove(boardCopy);
}


int Computer::evaluateBoard(const Board &board)
{
    // Checking for Rows for X or O victory.
    for (int row = 0; row<board.getSize(); row++){
    		if(board.checkRowForVictory(row)){
    			if(board.getCellValue(Cell{row,0})==m_mark) return 10;
    			else return -10;
    		}
    }

    // Checking for Columns for X or O victory.
    for (int col = 0; col<board.getSize(); col++){
		if(board.checkColForVictory(col)){
			if(board.getCellValue(Cell{0,col})==m_mark) return 10;
			else return -10;
		}
	}

    if(board.checkDiagonalsForVictory()){
		if(board.getCellValue(Cell{1,1})==m_mark) return 10;
		else return -10;
	}
    return 0;
}

int Computer::applyMiniMax(Board& board, int depth, bool isMax)
{
	int score = evaluateBoard(board);
    // If Maximizer has won the game return his/her evaluated score
    if (score == 10)
        return score;

    // If Minimizer has won the game return his/her evaluated score
    if (score == -10)
        return score;

    // If there are no more moves and no winner then it is a tie
    if (!board.isMoveLeft()) return 0;

    // If this maximizer's move
	if (isMax)
	{
		int best = -1000;

		// Traverse all cells
		for (int i = 0; i<board.getSize(); i++)
		{
			for (int j = 0; j<board.getSize(); j++)
			{
				// Check if cell is empty
				if (board.getCellValue(Cell{i,j})==Mark::Empty)
				{
					// Make the move
					board.addMove(Cell{i,j}, m_mark);

					// Call minimax recursively and choose the maximum value
					best = max( best,
							applyMiniMax(board, depth+1, !isMax));

					// Undo the move
					board.addMove(Cell{i,j},Mark::Empty);
				}
			}
		}
		return best;
	}
	else
	{
		int best = 1000;

		// Traverse all cells
		for (int i = 0; i<board.getSize(); i++)
		{
			for (int j = 0; j<board.getSize(); j++)
			{
				// Check if cell is empty
				if (board.getCellValue(Cell{i,j})==Mark::Empty)
				{
					// Make the move - di di
					board.addMove(Cell{i,j}, getOpponentMark());

					// Call minimax recursively and choose the minimum value
					best = min(best,
							applyMiniMax(board, depth+1, !isMax));
					// Undo the move
					board.addMove(Cell{i,j},Mark::Empty);
				}
			}
		}
		return best;
	}
}


Cell Computer::findBestMove(Board& board)
{
    int bestVal = -1000;
    Cell bestMove(-1,-1);

    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal value.
    for (int i = 0; i<board.getSize(); i++)
    {
        for (int j = 0; j<board.getSize(); j++)
        {
            // Check if cell is empty
            if (board.getCellValue(Cell{i,j})==Mark::Empty)
            {
                // Make the move
            		board.addMove(Cell{i,j}, m_mark);

                // compute evaluation function for this move.
                int moveVal = applyMiniMax(board, 0, false);

                // Undo the move
                board.addMove(Cell{i,j},Mark::Empty);

                // If the value of the current move is
                // more than the best value, then update best/
                if (moveVal > bestVal)
                {
                    bestMove.setRow(i);
                    bestMove.setCol(j);
                    bestVal = moveVal;
                }
            }
        }
    }

    cout<< "PC wants to play at Cell("<<bestMove.getRow()<<","<< bestMove.getCol()<<")"<< endl;
    return bestMove;
}
