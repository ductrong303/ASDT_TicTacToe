/*
 * Computer.h
 *
 *  Created on: 01.11.2025
 *      Author: Admin
 */
/**
 * @file Computer.h
 * @brief Declaration of the Computer class implementing an AI player.
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_

#include "Player.h"
/**
 * @class Computer
 * @brief AI-controlled player using minimax (and optionally random fallback) to choose moves.
 */
class Computer: public Player
{
public:
    /**
     * @brief Constructs a computer player with the given mark.
     * @param mark Mark assigned to this computer player.
     */
	Computer(Mark mark);

    /**
     * @brief Virtual destructor.
     */
	virtual ~Computer();

    /**
     * @brief Gets the next move for the computer based on the current board.
     * @param board Current board state.
     * @return Cell chosen by the AI.
     */
	Cell getNextMove(const Board& board);

    /**
     * @brief Converts a game outcome into a score, factoring in search depth.
     * @param depth Current depth of the minimax search.
     * @return Score from the perspective of this player.
     */
	int returnScore(int depth);

    /**
     * @brief Minimax algorithm applied on a given board state.
     * @param board Board state to evaluate and explore.
     * @param depth Current depth of recursion.
     * @param isMax True if maximizing player's turn, false for minimizing.
     * @return Best achievable score from this state.
     */
	int applyMiniMax(Board& board, int depth, bool isMax);

    /**
     * @brief Evaluates the given board and returns a heuristic score.
     * @param board Board state to evaluate.
     * @return Positive score for advantage, negative for disadvantage, zero for neutral.
     */
	int evaluateBoard(const Board& board);

    /**
     * @brief Finds the best move for the computer by exploring possible moves.
     * @param board Board state that can be modified during the search.
     * @return Cell representing the best move found.
     */
	Cell findBestMove(Board& board);
};

#endif /* COMPUTER_H_ */
