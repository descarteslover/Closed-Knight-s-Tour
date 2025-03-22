#include <iostream>
#include <fstream>
#include <string>
#include "Queue.h"
#include "Stack.h"
#include "ArgumentManager.h"

using namespace std;
const int TOTAL_MOVE_CHOICES = 8;
char possibleMoves[TOTAL_MOVE_CHOICES] = {'A','B','C','D','E','F','G','H'};
int NUM_ROWS;
int NUM_COLS;
int startRow;
int startCol;
int moveNumber = 0;
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
			if (board[row + 2][col - 1] == 0) {
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

bool CheckLastMove(int** board, int row, int col, char move) {
	switch (move) {
	case 'A':
		if (col + 2 < NUM_COLS && row - 1 >= 0) {
			if (board[row - 1][col + 2] == 1) {
				return true;
			}
		}
		return false;
	case 'B':
		if (col - 1 >= 0 && row - 2 >= 0) {
			if (board[row - 2][col - 1] == 1) {
				return true;
			}
		}
		return false;
	case 'C':
		if (col - 2 >= 0 && row + 1 < NUM_ROWS) {
			if (board[row + 1][col - 2] == 1) {
				return true;
			}
		}
		return false;
	case 'D':
		if (col + 1 < NUM_COLS && row + 2 < NUM_ROWS) {
			if (board[row + 2][col + 1] == 1) {
				return true;
			}
		}
		return false;
	case 'E':
		if (col + 1 < NUM_COLS && row - 2 >= 0) {
			if (board[row - 2][col + 1] == 1) {
				return true;
			}
		}
		return false;
	case 'F':
		if (col - 2 >= 0 && row - 1 >= 0) {
			if (board[row - 1][col - 2] == 1) {
				return true;
			}
		}
		return false;
	case 'G':
		if (col - 1 >= 0 && row + 2 < NUM_ROWS) {
			if (board[row + 2][col - 1] == 1) {
				return true;
			}
		}
		return false;
	case 'H':
		if (col + 2 < NUM_COLS && row + 1 < NUM_ROWS) {
			if (board[row + 1][col + 2] == 1) {
				return true;
			}
		}
		return false;
	}
}

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

void DrawBoard(int** board, ofstream& fout) { //FIX ME //I THINK THIS IS FIXED
	int maxSize = 2;
	int size = 0;
	for (int col = 0; col < NUM_COLS; col++) {
		fout << "+--";
	}
	fout << "+" << endl;
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			if (board[row][col] >= 0) {
				size = to_string(board[row][col]).length();
				if (size < maxSize) {
					fout << "| " << board[row][col];
				}
				else {
					fout << "|" << board[row][col];
				}
			}
			else {
				fout << "|XX";
			}
		}
		fout << "|" << endl;
		for (int col = 0; col < NUM_COLS; col++) {
			fout << "+--";
		}
		fout << "+" << endl;
	}
}

Queue<char>* FindPossibleMoves(int** board, int rowPos, int colPos) { //COME BACK TO ME, ENSURE THE QUEUE IS BEING MADE CORRECTLY
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

void UndoMove(int** board, int& rowPos, int& colPos, char move) {//backtracking //STILL NEEDS IMPLEMENTING BASICALLY REVERSING THE LOGIC OF MAKEMOVE
	switch (move) {
	case 'A':
		board[rowPos][colPos] = 0;
		rowPos += 1;
		colPos -= 2;
		break;
	case 'B':
		board[rowPos][colPos] = 0;
		rowPos += 2;
		colPos += 1;
		break;
	case 'C':
		board[rowPos][colPos] = 0;
		rowPos -= 1;
		colPos += 2;
		break;
	case 'D':
		board[rowPos][colPos] = 0;
		rowPos -= 2;
		colPos -= 1;
		break;
	case 'E':
		board[rowPos][colPos] = 0;
		rowPos += 2;
		colPos -= 1;
		break;
	case 'F':
		board[rowPos][colPos] = 0;
		rowPos += 1;
		colPos += 2;
		break;
	case 'G':
		board[rowPos][colPos] = 0;
		rowPos -= 2;
		colPos += 1;
		break;
	case 'H':
		board[rowPos][colPos] = 0;
		rowPos -= 1;
		colPos -= 2;
		break;
	}
}
int numZeroes(int** board) {
	int count = 0;
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLS; j++) {
			if (board[i][j] == 0) {
				count++;
			}
		}
	}
	return count;
}
Queue<char>* FindPossibleLastMove(int** board, int rowPos, int colPos) {
	Queue<char>* queue = new Queue<char>;
	for (int i = 0; i < TOTAL_MOVE_CHOICES; i++) {
		//cout << "Iteration " << i << endl;
		//cout << possibleMoves[i] << endl;
		//cout << rowPos << " " << colPos << endl;
		if (CheckLastMove(board, rowPos, colPos, possibleMoves[i])) {
			queue->Enqueue(possibleMoves[i]);
			//cout << "Entered if" << endl;
		}
	}
	return queue;
}
bool IsTourClosed(int** board, int startRow, int startCol) { //PlaceQueens analog FIX ME
	int count = 0;
	char move = '\0';
	Stack<Queue<char>*> stack;
	Queue<char>* queue = FindPossibleMoves(board, startRow, startCol);
	move = queue->Front();
	stack.Push(queue);
	moveNumber++;
	MakeMove(board, startRow, startCol, move);
	while (!stack.IsEmpty()) { //while stack is not empty::as long as there are moves
		queue = FindPossibleMoves(board, startRow, startCol);
		//queue->Print();
		if (queue->IsEmpty()) { //if we didn't find any moves from our current place
			while (true) { //backtrack
				delete queue; //clean up this queue
				if (stack.IsEmpty()) {
					return false; // There is no solution
				}
				queue = stack.Pop();
				move = queue->Dequeue();
				//cout << "Backtrack and remove " << moveNumber << " from (" << startRow << ", " << startCol << ")" << endl;
				UndoMove(board, startRow, startCol, move);
				moveNumber--;
				//DrawBoard(board);
				if (!queue->IsEmpty()) {
					break; //More moves possible
				}
			}
		}
		//forge ahead;
		//cout << "Forging Ahead. Place " << moveNumber << " on (" << startRow << ", " << startCol << ")" << endl;
		move = queue->Front();
		stack.Push(queue);
		moveNumber++;
		//DrawBoard(board);
		MakeMove(board, startRow, startCol, move);
		count = numZeroes(board);
		if (count == 0) { //MAJOR KEY
			queue = FindPossibleLastMove(board, startRow, startCol);
			if (!queue->IsEmpty()) {
				return true;
			}
			else continue;
		
		}
	}
	return false;
} 

int** ReadFile(ifstream& fin) {
	//ifstream fin("input2.txt");
	int row, col;
	fin >> NUM_ROWS >> NUM_COLS;
	int** board = new int* [NUM_ROWS];
	for (int i = 0; i < NUM_ROWS; i++) {
		board[i] = new int[NUM_COLS];
		for (int j = 0; j < NUM_COLS; j++) {
			board[i][j] = 0;
		}
	}
	fin >> startRow >> startCol;
	fin >> numHoles;
	for (int i = 0; i < numHoles; i++) {
		fin >> row >> col;
		board[row][col] = -1;
	}
	fin.close();
	return board;
}
int main(int argc, char* argv[]) {
	/*const int numCols = 3;
	const int numRows = 3;*/
	//matrix[1][1] = -1;
	/*int i = 0;
	int j = 0;*/
	ArgumentManager am(argc, argv);
	string input = am.get("input");
	string output = am.get("output");
	ifstream fin(input);
	ofstream fout(output);
	int** board = ReadFile(fin);
	cout << "Starting at (" << startRow << ", " << startCol << ")" << endl;
	moveNumber++;
	board[startRow][startCol] = moveNumber;
	//DrawBoard(board);

	bool straightBoolin = IsTourClosed(board, startRow, startCol);
	if (straightBoolin) {
		fout << "A closed tour exists!" << endl;
		DrawBoard(board, fout);
	}
	else {
		fout << "A closed tour does not exist!" << endl;
	}
	fout.close();
	//DrawBoard(board);
	//Queue<char>* queue = FindPossibleMoves(board, startRow, startCol);
	//char move = queue->Front();
	//moveNumber++;
	//MakeMove(board, startRow, startCol, move);
	////cout << "Starting at (" << startRow << ", " << startCol << ")" << endl;
	//DrawBoard(board);
	//queue = FindPossibleMoves(board, startRow, startCol);
	//move = queue->Front();
	//moveNumber++;
	//MakeMove(board, startRow, startCol, move);
	//DrawBoard(board);
	/*DrawBoard(board);*/
	//bool straightBoolin = IsTourClosed(board, startRow, startCol);
	/*queue->Print();*/
	/*bool straightBoolin = CheckMove(matrix, i, j, 'H');
	if (straightBoolin) {
		cout << "This is how we win" << endl;
	}
	else {
		cout << "This is how we lose" << endl;
	}*/
}