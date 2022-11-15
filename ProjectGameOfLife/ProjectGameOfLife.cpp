#include <iostream>

using namespace std;

class Board {

private:
	int numOfGenerations = 1;
	int neighborCount = 0;
	string currentBoard[10][10];
	string nextBoard[10][10];

public:

	void startGame() {
		cout << "Welcome to the Game of Life. How many generations would you like to play at most?: ";
		cin >> numOfGenerations;
		cout << "Please input the initial state of the world one character \"X\" or \"-\" at a time separated by spaces." << endl;

		// Initialize current and next boards
		for (int i = 0; i < 10; i++) {

			for (int j = 0; j < 10; j++) {
				cin >> currentBoard[i][j];
				nextBoard[i][j] = currentBoard[i][j];
			}

		}

		cout << endl;

		// Generation Changes	
		for (int x = 0; x < numOfGenerations; x++) {

			for (int i = 0; i < 10; i++) {

				for (int j = 0; j < 10; j++) {

					neighborCount = 0;

					if (currentBoard[i - 1][j] == "X") neighborCount++;
					if (currentBoard[i - 1][j + 1] == "X") neighborCount++;
					if (currentBoard[i][j + 1] == "X") neighborCount++;
					if (currentBoard[i + 1][j + 1] == "X") neighborCount++;
					if (currentBoard[i + 1][j] == "X") neighborCount++;
					if (currentBoard[i + 1][j - 1] == "X") neighborCount++;
					if (currentBoard[i][j - 1] == "X") neighborCount++;
					if (currentBoard[i - 1][j - 1] == "X") neighborCount++;


					if ((neighborCount > 3) || (neighborCount < 2)) {
						nextBoard[i][j] = "-";
					}
					else if (neighborCount == 3) {
						nextBoard[i][j] = "X";
					}

				}
			}

			// Check for a dead end

			bool isDeadEnd = true;

			for (int i = 0; i < 10; i++) {

				for (int j = 0; j < 10; j++) {

					if (currentBoard[i][j] != nextBoard[i][j]) {
						isDeadEnd = false;
					}

				}

			}

			if (isDeadEnd) {

				cout << "Things got stagnant in the Game of Life at step " << x << "." << endl;
				break;

			}


			// Copy nextBoard to currentBoard

			for (int i = 0; i < 10; i++) {

				for (int j = 0; j < 10; j++) {
					currentBoard[i][j] = nextBoard[i][j];
				}

			}

			// Print Board
			for (int i = 0; i < 10; i++) {

				for (int j = 0; j < 10; j++) {
					cout << currentBoard[i][j] << " ";
				}

				cout << endl;

			}

			cout << endl;

		}

		cout << "Exiting the Game of Life." << endl;

	}
};

int main() {
	Board test;
	test.startGame();
}

/*
		OUTPUT

	Welcome to the Game of Life. How many generations would you like to play at most?: 10
	Please input the initial state of the world one character "X" or "-" at a time separated by spaces.
	- - - - - - - - - -
	- X - - - - - - X -
	- - X - - - - X - -
	- - - X - - X - - -
	- - - - X X - - - -
	- - - - X X - - - -
	- - - X - - X - - -
	- - X - - - - X - -
	- X - - - - - - X -
	- - - - - - - - - -

	- - - - - - - - - -
	- - - - - - - - - -
	- - X - - - - X - -
	- - - X X X X - - -
	- - - X - - X - - -
	- - - X - - X - - -
	- - - X X X X - - -
	- - X - - - - X - -
	- - - - - - - - - -
	- - - - - - - - - -

	- - - - - - - - - -
	- - - - - - - - - -
	- - - X X X X - - -
	- - X X X X X X - -
	- - X X - - X X - -
	- - X X - - X X - -
	- - X X X X X X - -
	- - - X X X X - - -
	- - - - - - - - - -
	- - - - - - - - - -

	- - - - - - - - - -
	- - - - X X - - - -
	- - X - - - - X - -
	- - - - - - - - - -
	- X - - - - - - X -
	- X - - - - - - X -
	- - - - - - - - - -
	- - X - - - - X - -
	- - - - X X - - - -
	- - - - - - - - - -

	- - - - - - - - - -
	- - - - - - - - - -
	- - - - - - - - - -
	- - - - - - - - - -
	- - - - - - - - - -
	- - - - - - - - - -
	- - - - - - - - - -
	- - - - - - - - - -
	- - - - - - - - - -
	- - - - - - - - - -

	Things got stagnant in the Game of Life at step 4.
	Exiting the Game of Life.

	C:\Users\User\code\school_bcc\ProjectGameOfLife\Debug\ProjectGameOfLife.exe (process 16860) exited with code 0.
	Press any key to close this window . . .

*/