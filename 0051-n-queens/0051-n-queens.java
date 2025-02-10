class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<List<String>>();
        char[][] board = new char[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                board[i][j] = '.';
            }
        }
        dfs(0, board, ans);
        return ans;
    }
    private void dfs(int col, char[][] board, List<List<String>> ans) {
        if (col == board.length) {
            ans.add(convertToList(board));
            return;
        }
        for (int row = 0; row < board.length; row++) {
            if(isSafe(row, col, board) == true) {
                board[row][col] = 'Q';
                dfs(col + 1, board, ans);
                board[row][col] = '.';
            }
        }
    }
    private boolean isSafe(int row, int col, char[][] board) {
        int duprow = row;
        int dupcol = col;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = duprow;
        col = dupcol;
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }
        row = duprow;
        col = dupcol;
        while (col >= 0 && row < board.length) {
            if (board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    private List<String> convertToList(char[][] board) {
        List<String> res = new ArrayList<>();
        for (char[] row : board) {
            res.add(new String(row)); // Convert char[] to String
        }
        return res;
    }
}