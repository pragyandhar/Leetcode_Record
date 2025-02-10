class Solution {
    public void solveSudoku(char[][] board) {
        SS(board);
    }
    private boolean SS(char[][] b) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (b[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(b, i, j, c)) {
                            b[i][j] = c;
                            if (SS(b) == true) return true;
                            else b[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    private boolean isValid(char[][] b, int row, int col, char c) {
        for(int i = 0; i < 9; i++) {
            if (b[i][col] == c) return false;
            if (b[row][i] == c) return false;
            if (b[3 * (row/3) + i / 3][3 * (col/3) + i % 3] == c) return false;
        }
        return true;
    }
}