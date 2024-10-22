class Solution {
    
    public void solveSudoku(char[][] board) {
        solve(board);
    }
    
    // Helper function to solve the Sudoku puzzle
    private boolean solve(char[][] board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // Find the first empty cell
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        // Try placing numbers 1-9 in the empty cell
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num;
                            
                            // Recur to solve the rest of the board
                            if (solve(board)) {
                                return true;  // If successful, return true
                            } else {
                                // If the current setup is invalid, reset the cell
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;  // Return false if no number fits in the empty cell
                }
            }
        }
        return true;  // Return true when the entire board is filled correctly
    }
    
    // Helper function to check if placing 'num' in board[row][col] is valid
    private boolean isValid(char[][] board, int row, int col, char num) {
        // Check if the number is valid in the current row, column, and 3x3 grid
        for (int i = 0; i < 9; i++) {
            // Check the row
            if (board[row][i] == num) {
                return false;
            }
            // Check the column
            if (board[i][col] == num) {
                return false;
            }
            // Check the 3x3 subgrid
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) {
                return false;
            }
        }
        return true;
    }
}
