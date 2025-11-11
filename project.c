/*
 * C Program: Sudoku Grid Validator
 *
 * This program checks if a 9x9 Sudoku grid is a valid solution.
 * It validates three conditions as required by the rules of Sudoku:
 * 1. Each row must contain the numbers 1-9 exactly once.
 * 2. Each column must contain the numbers 1-9 exactly once.
 * 3. Each of the nine 3x3 subgrids must contain the numbers 1-9 exactly once.
 */

#include <stdio.h>

// --- Helper Function ---
/**
 * @brief Checks a 9-element array (representing a row, col, or subgrid)
 * to see if it contains the numbers 1-9 exactly once.
 * @param arr An array of 9 integers.
 * @return 1 (true) if the check passes, 0 (false) otherwise.
 */
int check_unit(int arr[9]) {
    // This is the "array-based checklist" mentioned in the project brief.
    // We use an array of size 10 (indexed 0-9) for convenience.
    // We will ignore index 0.
    // checklist[1] will count occurrences of '1', checklist[2] for '2', etc.
    int checklist[10] = {0}; // Initialize all counts to 0

    for (int i = 0; i < 9; i++) {
        int num = arr[i];

        // Basic check: Is the number in the valid 1-9 range?
        if (num < 1 || num > 9) {
            return 0; // Invalid number found
        }

        // Increment the count for this number
        checklist[num]++;

        // If we've seen this number more than once, it's an invalid unit
        if (checklist[num] > 1) {
            return 0; // Duplicate number found
        }
    }

    // After checking all 9 elements, if we never returned 0,
    // it means all numbers 1-9 were present exactly once.
    return 1;
}

// --- Rule 1: Check Rows ---
/**
 * @brief Checks if all rows in the grid are valid.
 * @param grid The 9x9 Sudoku grid.
 * @return 1 (true) if all rows are valid, 0 (false) otherwise.
 */
int check_rows(int grid[9][9]) {
    // Use nested loops as required
    for (int r = 0; r < 9; r++) { // For each row 'r'
        // We create a temporary 1D array to hold the current row
        int row_unit[9];
        for (int c = 0; c < 9; c++) { // For each column 'c' in that row
            row_unit[c] = grid[r][c];
        }

        // Validate the extracted row
        if (check_unit(row_unit) == 0) {
            return 0; // This row is invalid, so no need to check further
        }
    }

    // If the loop finishes, all rows were valid
    return 1;
}

// --- Rule 2: Check Columns ---
/**
 * @brief Checks if all columns in the grid are valid.
 * @param grid The 9x9 Sudoku grid.
 * @return 1 (true) if all columns are valid, 0 (false) otherwise.
 */
int check_columns(int grid[9][9]) {
    // Use nested loops as required
    for (int c = 0; c < 9; c++) { // For each column 'c'
        // We create a temporary 1D array to hold the current column
        int col_unit[9];
        for (int r = 0; r < 9; r++) { // For each row 'r' in that column
            col_unit[r] = grid[r][c];
        }

        // Validate the extracted column
        if (check_unit(col_unit) == 0) {
            return 0; // This column is invalid
        }
    }

    // If the loop finishes, all columns were valid
    return 1;
}

// --- Rule 3: Check Subgrids ---
/**
 * @brief Checks if all 3x3 subgrids (boxes) in the grid are valid.
 * @param grid The 9x9 Sudoku grid.
 * @return 1 (true) if all subgrids are valid, 0 (false) otherwise.
 */
int check_subgrids(int grid[9][9]) {
    // This is the "hardest" one, as the brief says.
    // We loop through the 9 subgrids. We can identify each subgrid
    // by its top-left corner (row 0, 3, 6 and col 0, 3, 6).
    for (int start_row = 0; start_row < 9; start_row += 3) {
        for (int start_col = 0; start_col < 9; start_col += 3) {
            
            // Now, extract the 9 numbers from this 3x3 subgrid
            int subgrid_unit[9];
            int k = 0; // Index for the subgrid_unit array

            // Nested loops to go through the 3x3 box
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
                    subgrid_unit[k] = grid[start_row + r][start_col + c];
                    k++;
                }
            }

            // Validate the extracted subgrid
            if (check_unit(subgrid_unit) == 0) {
                return 0; // This subgrid is invalid
            }
        }
    }

    // If all 9 subgrids are checked and valid
    return 1;
}

// --- Main Function ---
/**
 * @brief Main entry point of the program.
 * Initializes a Sudoku grid and prints if it's a valid solution.
 */
int main() {
    // 1. The Grid: "Hard-code" a completed puzzle
    
    // A valid solution for testing
    int grid[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };

    /*
    // An invalid solution for testing (duplicate '5' in top row)
    int grid[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 5}, // Invalid row
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };
    */

    // 3. The main() Function: Call the three checks
    int rows_valid = check_rows(grid);
    int cols_valid = check_columns(grid);
    int subgrids_valid = check_subgrids(grid);

    // Use if-else logic to check the return values
    // A solution is valid ONLY if all three checks pass
    if (rows_valid == 1 && cols_valid == 1 && subgrids_valid == 1) {
        // 4. Output: Print the final verdict
        printf("VALID SOLUTION\n");
    } else {
        // 4. Output: Print the final verdict
        printf("INVALID SOLUTION\n");
    }

    return 0; // Indicate successful execution
}