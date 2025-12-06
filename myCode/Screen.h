/*
 * Screen.h
 *
 *  Created on: 3 Nov 2025
 *      Author: ductr
 */
/**
 * @file Screen.h
 * @brief Abstract base class for rendering the game board.
 */
#ifndef SCREEN_H_
#define SCREEN_H_
#include "Cell.h"
#include <vector>
#include "Board.h"
using namespace std;

/**
 * @class Screen
 * @brief Provides an abstract interface for displaying a board to the user.
 *
 * Concrete implementations (e.g. console, GUI) must implement the print() function.
 */
class Screen
{
public:
    /**
     * @brief Default constructor.
     */
	Screen();

    /**
     * @brief Virtual destructor for proper polymorphic cleanup.
     */
	virtual ~Screen();

    /**
     * @brief Renders the current board state.
     * @param board Board instance to print.
     */
	virtual void print(const Board& board) const = 0;
};

#endif /* SCREEN_H_ */
