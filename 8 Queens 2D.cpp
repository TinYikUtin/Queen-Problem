#include <iostream>

const int N = 8; // The size of the chessboard

// Function to print the chessboard
void printChessboard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check the left side of the current row
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the 8 Queens problem
bool solveNQueens(int board[N][N], int col) {
    // All queens are placed, return true
    if (col >= N) {
        return true;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place the queen

            // Recur to place the rest of the queens
            if (solveNQueens(board, col + 1)) {
                return true;
            }

            // If placing the queen doesn't lead to a solution, backtrack
            board[i][col] = 0;
        }
    }

    // No solution exists
    return false;
}

int main() {
    int board[N][N] = {{0}};

    if (solveNQueens(board, 0)) {
        std::cout << "Solution exists:" << std::endl;
        printChessboard(board);
    } else {
        std::cout << "No solution exists." << std::endl;
    }

    return 0;
}
