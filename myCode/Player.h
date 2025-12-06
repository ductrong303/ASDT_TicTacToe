/*
 * Player.h
 *
 *  Created on: 01.11.2025
 *      Author: Admin
 */
/**
 * @file Player.h
 * @brief Declaration of the Player base class and related types.
 */
#ifndef PLAYER_H_
#define PLAYER_H_
#include <vector>
#include <iostream>
#include "Cell.h"
#include "Board.h"
using namespace std;

/**
 * @enum PlayerType
 * @brief Types of players supported by the game.
 */
enum class PlayerType{
	Human, Computer
};

/**
 * @class Player
 * @brief Abstract base class for all players participating in the game.
 *
 * A player owns a mark (X or O) and must implement a move-selection strategy.
 */
class Player
{
protected:
    /**
     * @brief Mark associated with the player (X or O).
     */
	Mark m_mark;
public:
    /**
     * @brief Constructs a player with the given mark.
     * @param mark Mark assigned to this player.
     */
	Player(Mark mark);

    /**
     * @brief Virtual destructor to allow polymorphic destruction.
     */
	virtual ~Player();

    /**
     * @brief Computes and returns the next move for this player.
     * @param board Current state of the board.
     * @return Cell chosen by the player.
     */
	virtual Cell getNextMove(const Board& board)=0;

    /**
     * @brief Returns the mark owned by this player.
     * @return Player's mark.
     */
	Mark getMark() const;

    /**
     * @brief Returns the mark owned by this player.
     * @return Player's mark.
     */
	Mark getOpponentMark() const;

};

#endif /* PLAYER_H_ */
