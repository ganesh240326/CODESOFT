//tictactoe program
#include <iostream>
#include <vector>

using namespace std;

// Function to display the board
void displayBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full (draw condition)
bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to get the player's move and update the board
bool makeMove(vector<vector<char>>& board, int row, int col, char player) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

int main() {
    char playAgain = 'y';
    while (playAgain == 'y' || playAgain == 'Y') {
        vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize a 3x3 board
        char currentPlayer = 'X'; // X always starts
        int row, col;
        bool gameOver = false;

        // Game loop
        while (!gameOver) {
            displayBoard(board);
            cout << "Player " << currentPlayer << "'s turn. Enter row and column (0, 1, 2): ";
            cin >> row >> col;

            // Validate input
            if (row < 0 || row > 2 || col < 0 || col > 2 || !makeMove(board, row, col, currentPlayer)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            // Check for win or draw
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (isBoardFull(board)) {
                displayBoard(board);
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        // Ask if players want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;
    return 0;
}