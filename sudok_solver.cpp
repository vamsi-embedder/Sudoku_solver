#include <iostream>

using namespace std;

#define SIZE 9

// Function to print Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {

    cout << "\nSolved Sudoku Puzzle:\n\n";

    for (int row = 0; row < SIZE; row++) {

        for (int col = 0; col < SIZE; col++) {

            cout << grid[row][col] << " ";
        }

        cout << endl;
    }
}

// Check if number is safe to place
bool isSafe(int grid[SIZE][SIZE],
            int row,
            int col,
            int num) {

    // Check row
    for (int x = 0; x < SIZE; x++) {

        if (grid[row][x] == num) {

            return false;
        }
    }

    // Check column
    for (int x = 0; x < SIZE; x++) {

        if (grid[x][col] == num) {

            return false;
        }
    }

    // Check 3x3 subgrid
    int startRow = row - row % 3;

    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (grid[i + startRow][j + startCol] == num) {

                return false;
            }
        }
    }

    return true;
}

// Solve Sudoku using backtracking
bool solveSudoku(int grid[SIZE][SIZE]) {

    int row, col;

    bool emptyFound = false;

    // Find empty cell
    for (row = 0; row < SIZE; row++) {

        for (col = 0; col < SIZE; col++) {

            if (grid[row][col] == 0) {

                emptyFound = true;

                goto EMPTY_CELL_FOUND;
            }
        }
    }

EMPTY_CELL_FOUND:

    // No empty cell means solved
    if (!emptyFound) {

        return true;
    }

    // Try numbers 1 to 9
    for (int num = 1; num <= 9; num++) {

        // Check validity
        if (isSafe(grid, row, col, num)) {

            // Place number
            grid[row][col] = num;

            // Recursive solve
            if (solveSudoku(grid)) {

                return true;
            }

            // Backtrack
            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {

    // Sudoku puzzle
    int grid[SIZE][SIZE] = {

        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    cout << "=====================================\n";
    cout << "         SUDOKU SOLVER\n";
    cout << "=====================================\n";

    cout << "\nInput Sudoku Puzzle:\n\n";

    for (int row = 0; row < SIZE; row++) {

        for (int col = 0; col < SIZE; col++) {

            cout << grid[row][col] << " ";
        }

        cout << endl;
    }

    // Solve Sudoku
    if (solveSudoku(grid)) {

        printGrid(grid);
    }
    else {

        cout << "\nNo Solution Exists!\n";
    }

    return 0;
}