class Solution {
    int maxGold = 0;
    public void helper(int[][] grid, int r, int c, int currGold) {
        int n = grid.length;
        int m = grid[0].length;
        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0) return;

        int gold = grid[r][c];
        currGold += gold;
        maxGold = Math.max(maxGold, currGold);
        
        grid[r][c] = 0;

        helper(grid, r + 1, c, currGold);
        helper(grid, r - 1, c, currGold);
        helper(grid, r, c + 1, currGold);
        helper(grid, r, c - 1, currGold);

        grid[r][c] = gold;
    }
    public int getMaximumGold(int[][] grid) {
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] != 0) helper(grid, i, j, 0);
            }
        }
        return maxGold;
    }
}