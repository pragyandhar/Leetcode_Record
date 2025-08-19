class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] memo = new int[m][n];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        return solve(grid, m, n, memo, 0, 0);
    }

    private int solve(int[][] grid, int m, int n, int[][] memo, int i, int j) {
        //means we are at last row and column, just return the value
        if(i==m-1 && j==n-1){
            return memo[i][j]= grid[i][j];
        }
        if(memo[i][j]!=-1){
            return memo[i][j];
        }

        //row
        if(i==m-1){
            //can only go right as we are at the last row
            return memo[i][j]= grid[i][j] + solve(grid,m,n,memo,i,j+1);
        }else if(j==n-1){
            //means we are at last column we can only go downwards
            return memo[i][j]=grid[i][j] + solve(grid,m,n,memo,i+1,j);
        }else{
            //it is in middle where it can either go downward or right
            return memo[i][j]= grid[i][j] + Math.min(solve(grid,m,n,memo,i,j+1),
                                            solve(grid,m,n,memo,i+1,j));
        }
    }
}