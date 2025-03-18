#include <iostream>

using namespace std;

bool CheckMove(int** board, int row, int col, const int numRows, const int numCols, char move) {
	switch (move) {
	case 'A':
		if (col + 2 < numCols && row - 1 >= 0) {
			if (board[row - 1][col + 2] == 0) {
				return true;
			}
		}
		return false;
	case 'B':
		if (col - 1 >= 0 && row - 2 >= 0) {
			if (board[row - 2][col - 1] == 0) {
			return true;
			}
		}
			return false;
	case 'C':
		if (col - 2 >= 0 && row + 1 < numRows) {
			if (board[row + 1][col - 2] == 0) {
				return true;
			}
		}
		return false;
	case 'D': 
		if (col + 1 < numCols && row + 2 < numRows) {
			if (board[row + 2][col + 1] == 0) {
				return true;
			}
		}
		return false;
	case 'E':
		if (col + 1 < numCols && row - 2 >= 0) {
			if (board[row - 2][col + 1] == 0) {
				return true;
			}
		}
		return false;
	case 'F': 
		if (col - 2 >= 0 && row - 1 >= 0) {
			if (board[row - 1][col - 2] == 0) {
				return true;
			}
		}
		return false;
	case 'G':
		if (col - 1 >= 0 && row + 2 < numRows) {
			if (board[row + 1][col - 1] == 0) {
				return true;
			}
		}
		return false;
	case 'H':
		if (col + 2 < numCols && row + 1 < numRows) {
			if (board[row + 1][col + 2] == 0) {
				return true;
			}
		}
		return false;
	}
}

void MakeMove(int i, int j, char move); //forge ahead
void UndoMove(int i, int j, char move); //backtracking
int main() {
	const int numCols = 3;
	const int numRows = 3;
	int** matrix = new int* [numRows];
	for (int i = 0; i < numRows; i++) {
		matrix[i] = new int[numCols];
		for (int j = 0; j < numCols; j++) {
			matrix[i][j] = 0;
		}
	}
	int i = 0;
	int j = 0;
	bool straightBoolin = CheckMove(matrix, i, j, numCols, numRows, 'H');
	if (straightBoolin) {
		cout << "This is how we win" << endl;
	}
	else {
		cout << "This is how we lose" << endl;
	}
}