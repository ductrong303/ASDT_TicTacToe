/*
 * Console.h
 *
 *  Created on: 04.11.2025
 *      Author: Admin
 */
/**
 * @file Console.h
 * @brief Declaration of a console-based screen implementation.
 */
#ifndef CONSOLE_H_
#define CONSOLE_H_
#include <iostream>
#include "Screen.h"

/**
 * @class Console
 * @brief Screen implementation that prints the board to the standard output.
 */
class Console: public Screen
{
public:
    /**
     * @brief Default constructor.
     */
	Console();

    /**
     * @brief Virtual destructor.
     */
	virtual ~Console();

    /**
     * @brief Prints the current board to the console.
     * @param board Board instance to be displayed.
     */
	void print(const Board& board) const;
};

#endif /* CONSOLE_H_ */
