#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

void DrawBoard(int, bool**);
bool CheckMove(bool**, int, int, int);
bool PlaceQueens(bool**, int);

int main() {
    int size = 4;
    // Allocate the board we will be using
    bool** queens = new bool*[size];
    for(int i = 0; i < size; i++){
        queens[i] = new bool[size];
        for(int j = 0; j < size; j++)
            queens[i][j] = false;
    }

    DrawBoard(size, queens);

    if(PlaceQueens(queens, size)){
        cout << "Success!" << endl;
    }
    else {
        cout << "No solution!" << endl;
    }

    // Clean up the memory we allocated
    for(int i = 0; i < size; i++){
        delete[] queens[i];
    }
    delete[] queens;
}

bool PlaceQueens(bool** queens, int size){
    int col = 0; // the current column we are working
    int move = 0; // The current move for the queeen
    Stack<Queue<int>*> stack; // The stack of moves
    Queue<int>* queue = new Queue<int>;
    //For the first queen any row move is possible
    for(int row = 0; row < size; row++){
        queue->Enqueue(row); // all possible row moves for a column
    }

    move = queue->Front(); // pick the first row move
    stack.Push(queue); // store these moves
    queens[move][col] = true; // Place the queen
    col++;
    DrawBoard(size, queens);
    
    while(!stack.IsEmpty()){ // as long as there are moves
        queue = new Queue<int>; // Find the possible moves
        for(int row = 0; row < size; row++){
            if(CheckMove(queens, size, row, col)){
                queue->Enqueue(row); // a valid move
            }
        }
        if(queue->IsEmpty()){ // No moves, backtrack
            while(true) { // Backtrack
                delete queue; // clean up this queue
                col--; // move back a step
                if(stack.IsEmpty()){
                    return false; // There is no solution
                }
                queue = stack.Pop();
                move = queue->Dequeue(); // remove the front 
                queens[move][col] = false; // undo the queen placement
                cout << "Backtracking!" << endl;
                DrawBoard(size, queens);
                if(!queue->IsEmpty()) {
                    break; // More moves possible
                }
            }
        }
        
        // Forge ahead
        move = queue->Front(); // pick the first row move
        stack.Push(queue); // store these moves
        queens[move][col] = true; // Place the queen
        cout << "Forging Ahead! " << move << "," << col << endl;
        DrawBoard(size, queens);
        col++;
        if(col == size){ // Success!
            return true;
        }
    }
    return false;
}

void DrawBoard(int size, bool** queens){
    for(int col = 0; col < size; col++){
        cout << "+--";
    }
    cout << "+" << endl;
    for(int row  = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            if(queens[row][col]){
                cout << "| Q";
            }
            else {
                cout << "|  ";
            }
        }
        cout << "|" << endl;
        
        for(int col = 0; col < size; col++){
            cout << "+--";
        }
        cout << "+" << endl;
    }   
}

bool CheckMove(bool** queens, int size, int row, int col){

    for(int i = 0; i < size; i++){
        if(queens[i][col] || queens[row][i]){
            return false;
        }
    }

    for(int i = col, j = row; (i >= 0 && j >=0); i--, j--){
        if(queens[j][i]){
            return false;
        }
    }

    for(int i = col, j = row; (i >= 0 && j<size); i--, j++){
        if(queens[j][i]){
            return false;
        }
    }

    return true;
}