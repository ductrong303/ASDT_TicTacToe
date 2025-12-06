// Standard (system) header files
#include <iostream>
#include <cstdlib>
#include <ctime>   // time
#include "TicTacToe.h"
#include "Console.h"
// Add more standard header files as required
// #include <string>

using namespace std;



// Main program
int main ()
{
	cout << "ASDT_Lab1 started." << endl << endl;
	Console console1;
	TicTacToe game(3, &console1);
	game.play();
	return 0;
}
