#include <iostream>

using namespace std;

const int N = 9;

bool isValid(int board[N][N], int row, int col, int num) {
    // Check if the number is not in the current row, column and 3x3 sub-grid
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    int startRow = row / 3 * 3;
    int startCol = col / 3 * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {  // Find an empty cell
                for (int num = 1; num <= 9; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) {  // Recursively attempt to solve the rest
                            return true;
                        }
                        board[row][col] = 0;  // Reset if not solvable
                    }
                }
                return false;  // No valid number found, backtrack
            }
        }
    }
    return true;  // Solved
}

void printBoard(const int board[N][N]) {
    for (int row = 0; row < N; row++) {
        if (row % 3 == 0)
            cout << endl;
        for (int col = 0; col < N; col++) {
            if ( col % 3 == 0)
                cout << "\t";
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    int board[N][N] = {
        {0, 0, 0, 0, 1, 2, 3, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 4, 5, 3, 0, 0, 0, 0, 6},
        {0, 5, 0, 0, 0, 0, 6, 0, 0},
        {0, 0, 2, 0, 0, 7, 8, 0, 9},
        {0, 6, 0, 0, 0, 0, 7, 4, 2},
        {0, 7, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 5, 0, 0, 2, 0},
        {0, 0, 0, 9, 2, 1, 0, 0, 0}
    };
    cout << "Unsolved board\n";
    printBoard(board);
    if (solveSudoku(board)) {
        cout << "Solved board\n";
        printBoard(board);
    }
    else {
        cout << "No solution exists" << endl;
    }

    return 0;
}