/*
 * Screen.h
 *
 *  Created on: 3 Nov 2025
 *      Author: ductr
 */

#ifndef SCREEN_H_
#define SCREEN_H_
#include "Cell.h"
#include <vector>
#include "Board.h"
using namespace std;

class Screen
{
public:
	Screen();
	virtual ~Screen();
	virtual void print(const Board& board) const = 0;
};

#endif /* SCREEN_H_ */
