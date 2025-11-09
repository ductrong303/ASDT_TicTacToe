/*
 * Console.h
 *
 *  Created on: 04.11.2025
 *      Author: Admin
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_
#include <iostream>
#include "Screen.h"

class Console: public Screen
{
public:
	Console();
	virtual ~Console();
	void print(const Board& board) const;
};

#endif /* CONSOLE_H_ */
