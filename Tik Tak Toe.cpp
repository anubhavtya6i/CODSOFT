#include <iostream>
#include <cstdlib>  // For clearing the screen (system("cls") or system("clear"))

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[3][3]) {
    cout << "\nTic-Tac-Toe Board\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        cout << endl;
        if (i < 2) cout << "---|---|---\n";
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the board is full
bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Function to clear the screen (cross-platform solution)
void clearScreen() {
    // On Windows
    #ifdef _WIN32
        system("cls");
    #else
        // On Unix/Linux/MacOS
        system("clear");
    #endif
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char currentPlayer = 'X';  // Player X starts
    int row, col;
    bool gameOver = false;

    cout << "Welcome to Tic-Tac-Toe!\n";
    
    // Main game loop
    while (!gameOver) {
        clearScreen();  // Clear the screen before every new turn
        displayBoard(board);

        // Ask the current player to make a move
        cout << "Player " << currentPlayer << "'s turn.\n";
        cout << "Enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            // Make the move
            board[row][col] = currentPlayer;

            // Check for a win or draw
            if (checkWin(board, currentPlayer)) {
                clearScreen();
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            } else if (isBoardFull(board)) {
                clearScreen();
                displayBoard(board);
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                // Switch player
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move! Try again.\n";
            cin.ignore();  // To discard any invalid input
            cin.get();     // Wait for user to press Enter
        }
    }

    return 0;
}

