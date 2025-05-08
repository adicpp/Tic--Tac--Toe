#include <iostream>
#include <vector>
using namespace std;

bool checkWin(vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // row
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { // column
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || // diagonal 1
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) { // diagonal 2
        return true;
    }
    return false;
}

bool isBoardFull(vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false; // There's still an empty space
            }
        }
    }
    return true; // No empty space left
}

void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char player = 'X';
    
    // Example scenario 1: X wins on the first row
    board[0][0] = board[0][1] = board[0][2] = 'X';
    printBoard(board);
    if (checkWin(board, 'X')) {
        cout << "Player X wins!" << endl;
    }

    // Example scenario 2: Draw game
    board = {{'X', 'O', 'X'}, {'X', 'X', 'O'}, {'O', 'X', 'O'}};
    printBoard(board);
    if (isBoardFull(board) && !checkWin(board, 'X') && !checkWin(board, 'O')) {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
