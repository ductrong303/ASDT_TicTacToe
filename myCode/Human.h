/*
 * Human.h
 *
 *  Created on: 01.11.2025
 *      Author: Admin
 */
/**
 * @file Human.h
 * @brief Declaration of the Human player class.
 */

#ifndef HUMAN_H_
#define HUMAN_H_

#include "Player.h"
/**
 * @class Human
 * @brief Player implementation that obtains moves from user input.
 */
class Human: public Player
{
public:
    /**
     * @brief Constructs a human player with the given mark.
     * @param mark Mark assigned to this human player.
     */
	Human(Mark mark);

    /**
     * @brief Constructs a human player with the given mark.
     * @param mark Mark assigned to this human player.
     */
	virtual ~Human();

    /**
     * @brief Requests the next move from the user.
     * @param board Current state of the board (can be used to show or validate choices).
     * @return Cell chosen by the user.
     */
	Cell getNextMove(const Board& board);
};

#endif /* HUMAN_H_ */
