#include <iostream>
using namespace std;

char board[3][3]; // Game board
char currentPlayer; // 'X' or 'O'

// Function to initialize the game board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '1' + i * 3 + j; // Fill with 1-9
        }
    }
    currentPlayer = 'X'; // X always starts
}

// Function to display the game board
void displayBoard() {
    system("cls"); // Clear the console
    cout << "Tic Tac Toe\n";
    cout << "Player 1 (X) - Player 2 (O)\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j];
            if (j < 2) cout << " |";
        }
        if (i < 2) cout << "\n---|---|---\n";
    }
    cout << endl;
}

// Function to check for a win or draw
char checkWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return board[i][0]; // Row
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return board[0][i]; // Column
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2];

    // Check for draw (if all spots are filled)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return ' '; // Game still ongoing
        }
    }

    return 'D'; // Draw
}

// Function to handle player input
bool makeMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        return true;
    } else {
        return false; // Invalid move
    }
}

// Main game loop
int main() {
    initializeBoard();
    char winner = ' ';
    int move;

    while (winner == ' ') {
        displayBoard();
        cout << "Player " << (currentPlayer == 'X' ? "1" : "2") << " (" << currentPlayer << "), enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9 || !makeMove(move)) {
            cout << "Invalid move! Try again.\n";
            system("pause");
            continue;
        }

        winner = checkWinner(); // Check if someone has won or if it's a draw
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
    }

    displayBoard();
    if (winner == 'D') {
        cout << "It's a draw!" << endl;
    } else {
        cout << "Player " << (winner == 'X' ? "1" : "2") << " (" << winner << ") wins!" << endl;
    }

    return 0;
}
