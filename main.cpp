#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"
#include "Stack.h"

using namespace std;
const int TOTAL_MOVE_CHOICES = 8;
char possibleMoves[TOTAL_MOVE_CHOICES] = {'A','B','C','D','E','F','G','H'};
int NUM_ROWS;
int NUM_COLS;
int startRow;
int startCol;
int moveNumber;
int numHoles;

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

void MakeMove(int** board, int& rowPos, int& colPos, char move) { //forge ahead
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

void DrawBoard(int** board) { //FIX ME //I THINK THIS IS FIXED
	int maxSize = 2;
	int size = 0;
	for (int col = 0; col < NUM_COLS; col++) {
		cout << "+--";
	}
	cout << "+" << endl;
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			if (board[row][col] >= 0) {
				size = to_string(board[row][col]).length();
				if (size < maxSize) {
					cout << "| " << board[row][col];
				}
				else {
					cout << "|" << board[row][col];
				}
			}
			else {
				cout << "|XX";
			}
		}
		cout << "|" << endl;
		for (int col = 0; col < NUM_COLS; col++) {
			cout << "+--";
		}
		cout << "+" << endl;
	}
}

Queue<char>* FindPossibleMoves(int** board, const int rowPos, const int colPos) { //COME BACK TO ME, ENSURE THE QUEUE IS BEING MADE CORRECTLY
	Queue<char>* queue = new Queue<char>;
	for (int i = 0; i < TOTAL_MOVE_CHOICES; i++) {
		//cout << "Iteration " << i << endl;
		//cout << possibleMoves[i] << endl;
		//cout << rowPos << " " << colPos << endl;
		if (CheckMove(board, rowPos, colPos, possibleMoves[i])){
			queue->Enqueue(possibleMoves[i]);
			//cout << "Entered if" << endl;
		}
	}
	return queue;
}

void UndoMove(int** board, int& row, int& col, char move) {//backtracking //STILL NEEDS IMPLEMENTING BASICALLY REVERSING THE LOGIC OF MAKEMOVE

}

bool IsTourClosed(int** board, int startRow, int startCol) { //PlaceQueens analog FIX ME
	moveNumber = 1;
	char move = '\0';
	Stack<Queue<char>*> stack;
	Queue<char>* queue = FindPossibleMoves(board, startRow, startCol);
	move = queue->Front();
	stack.Push(queue);
	MakeMove(board, startRow, startCol, move);
	moveNumber++;
	while (!stack.IsEmpty()) { //as long as there are moves
		queue = FindPossibleMoves(board, startRow, startCol);
		if (queue->IsEmpty()) {
			while (true) {
				delete queue;
				moveNumber;
				queue = stack.Pop();
				move = queue->Dequeue();
				UndoMove(board, startRow, startCol, move);
				cout << "Backtracking" << endl;
				if (!queue->IsEmpty()) {
					break; //More moves possible
				}
			}
		}
	}

} 

int** ReadFile() {
	ifstream fin("input1.txt");
	int row, col;
	fin >> NUM_ROWS >> NUM_COLS;
	fin >> startRow >> startCol;
	int** board = new int* [NUM_ROWS];
	for (int i = 0; i < NUM_ROWS; i++) {
		board[i] = new int[NUM_COLS];
		for (int j = 0; j < NUM_COLS; j++) {
			board[i][j] = 0;
		}
	}
	fin >> numHoles;
	for (int i = 0; i < numHoles; i++) {
		fin >> row >> col;
		board[row][col] = -1;
	}
	return board;
}
int main() {
	/*const int numCols = 3;
	const int numRows = 3;*/
	//matrix[1][1] = -1;
	/*int i = 0;
	int j = 0;*/
	int** board = ReadFile();
	/*DrawBoard(board);*/
	bool straightBoolin = IsTourClosed(board, startRow, startCol);
	/*queue->Print();*/
	/*bool straightBoolin = CheckMove(matrix, i, j, 'H');
	if (straightBoolin) {
		cout << "This is how we win" << endl;
	}
	else {
		cout << "This is how we lose" << endl;
	}*/
}