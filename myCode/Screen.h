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

using namespace std;

class Screen
{
public:
	Screen();
	virtual ~Screen();
	virtual void print(const vector<vector<Mark>>& board, int boardSize) const = 0;
};

#endif /* SCREEN_H_ */
