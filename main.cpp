#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"
#include "Stack.h"

using namespace std;
const int TOTAL_MOVE_CHOICES = 8;
const char possibleMoves[8] = { 'A','B','C','D','E','F','G','H'};
int NUM_ROWS;
int NUM_COLS;
int moveNumber;

bool CheckMove(int** board, int row, int col, char move) {
	switch (move) {
	case 'A':
		if (col + 2 < NUM_COLS && row - 1 >= 0) {
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
		if (col - 2 >= 0 && row + 1 < NUM_ROWS) {
			if (board[row + 1][col - 2] == 0) {
				return true;
			}
		}
		return false;
	case 'D': 
		if (col + 1 < NUM_COLS && row + 2 < NUM_ROWS) {
			if (board[row + 2][col + 1] == 0) {
				return true;
			}
		}
		return false;
	case 'E':
		if (col + 1 < NUM_COLS && row - 2 >= 0) {
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
		if (col - 1 >= 0 && row + 2 < NUM_ROWS) {
			if (board[row + 1][col - 1] == 0) {
				return true;
			}
		}
		return false;
	case 'H':
		if (col + 2 < NUM_COLS && row + 1 < NUM_ROWS) {
			if (board[row + 1][col + 2] == 0) {
				return true;
			}
		}
		return false;
	}
} //PERFORM ANOTHER TEST ON ME

void MakeMove(int** board, int rowPos, int colPos, char move) { //forge ahead
	switch (move) {
	case 'A':
		rowPos -= 1;
		colPos += 2;
		board[rowPos][colPos] = moveNumber;
		break;
	case 'B':
		rowPos -= 2;
		colPos -= 1;
		board[rowPos][colPos] = moveNumber;
		break;
	case 'C':
		rowPos += 1;
		colPos -= 2;
		board[rowPos][colPos] = moveNumber;
		break;
	case 'D':
		rowPos += 2;
		colPos += 1;
		board[rowPos][colPos] = moveNumber;
		break;
	case 'E':
		rowPos -= 2;
		colPos += 1;
		board[rowPos][colPos] = moveNumber;
		break;
	case 'F':
		rowPos -= 1;
		colPos -= 2;
		board[rowPos][colPos] = moveNumber;
		break;
	case 'G':
		rowPos += 2;
		colPos -= 1;
		board[rowPos][colPos] = moveNumber;
		break;
	case 'H':
		rowPos += 1;
		colPos += 2;
		board[rowPos][colPos] = moveNumber;
		break;
	}
} 

void DrawBoard(int** board) { //FIX ME
	for (int col = 0; col < NUM_COLS; col++) {
		cout << "+--";
	}
	cout << "+" << endl;
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			if (board[row][col] > 0) {
				cout << " " << 
			}
		}
	}
}

Queue<char>* FindPossibleMoves(int** board, const int rowPos, const int colPos) {
	Queue<char>* queue = new Queue<char>;
	for (int i = 0; i < TOTAL_MOVE_CHOICES; i++) {
		if (CheckMove(board, rowPos, colPos,possibleMoves[i])){
			queue->Enqueue(possibleMoves[i]);
		}
	}
	return queue;
}

void UndoMove(int** board, int i, int j, char move, int& moveNumber) {//backtracking //FIX ME COME BACK TO THIS

}

bool IsTourClosed(int** board, int startRow, int startCol, const int numRows, const int numCols) { //PlaceQueens analog FIX ME
	moveNumber = 1;
	char move = '\0';
	Stack<Queue<char>*> stack;
	Queue<char>* queue = FindPossibleMoves(board, startRow, startCol);
	move = queue->Front();
	stack.Push(queue);
	MakeMove(board, startRow, startCol, move);
	moveNumber++;


} 
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
	/*bool straightBoolin = CheckMove(matrix, i, j, 'H');
	if (straightBoolin) {
		cout << "This is how we win" << endl;
	}
	else {
		cout << "This is how we lose" << endl;
	}*/
}