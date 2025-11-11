# coc-project-sudoku-grid-validator
🧩 Sudoku Grid Validator (C Program)

This is a C program that checks whether a given 9×9 Sudoku grid is a valid completed Sudoku solution.
It follows the three fundamental Sudoku rules to ensure correctness.


---

🚀 Features

✅ Validates Sudoku solution by checking:

1. Each row contains numbers 1–9 exactly once.


2. Each column contains numbers 1–9 exactly once.


3. Each 3×3 subgrid contains numbers 1–9 exactly once.



✅ Uses modular functions for clarity:

check_unit() → Validates a 1D array (row, column, or subgrid).

check_rows() → Checks all 9 rows.

check_columns() → Checks all 9 columns.

check_subgrids() → Checks all nine 3×3 subgrids.


✅ Easy to test different Sudoku grids by modifying the array in main().


---

📂 Project Structure

sudoku_validator.c

Key Functions:

Function	Description

check_unit(int arr[9])	Verifies if an array contains digits 1–9 exactly once
check_rows(int grid[9][9])	Checks all Sudoku rows
check_columns(int grid[9][9])	Checks all Sudoku columns
check_subgrids(int grid[9][9])	Checks all 3×3 subgrids
main()	Initializes a Sudoku grid and prints VALID SOLUTION or INVALID SOLUTION



---

🧠 How It Works

1. The grid is hard-coded inside the main() function.


2. Each Sudoku rule is tested separately using helper functions.


3. If all three checks return true, the program prints:

VALID SOLUTION

Otherwise:

INVALID SOLUTION




---

🧪 Example

✅ Valid Sudoku Grid

int grid[9][9] = {
    {5,3,4,6,7,8,9,1,2},
    {6,7,2,1,9,5,3,4,8},
    {1,9,8,3,4,2,5,6,7},
    {8,5,9,7,6,1,4,2,3},
    {4,2,6,8,5,3,7,9,1},
    {7,1,3,9,2,4,8,5,6},
    {9,6,1,5,3,7,2,8,4},
    {2,8,7,4,1,9,6,3,5},
    {3,4,5,2,8,6,1,7,9}
};

Output:

VALID SOLUTION

❌ Invalid Sudoku Grid

int grid[9][9] = {
    {5,3,4,6,7,8,9,1,5}, // Duplicate '5'
    ...
};

Output:

INVALID SOLUTION


---

🛠 Compilation & Execution

Use any C compiler (like GCC).

gcc sudoku_validator.c -o sudoku_validator
./sudoku_validator


---

📜 License

This project is open-source under the MIT License.
Feel free to use, modify, and share.


---

👨‍💻 Author

Sudarshan Singh Solanki
📘 Simple | Clean | Well-documented C Program
