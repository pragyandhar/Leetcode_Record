class Solution {
    void mark_islands(vector<vector<char>>& matrix, int x, int y, int row, int col){
        if(x < 0 || x >= row || y < 0 || y >= col || matrix[x][y] != '1') return;
        matrix[x][y] = '2'; //update as visited
        // dfs recursive calls
        mark_islands(matrix, x-1, y, row, col); // up
        mark_islands(matrix, x+1, y, row, col); // down
        mark_islands(matrix, x, y+1, row, col); // right
        mark_islands(matrix, x, y-1, row, col); // left
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0; // empty grid

        int no_of_islands = 0;

        int rows = grid.size();
        int cols = grid[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    mark_islands(grid, i, j, rows, cols); // dfs traversal 
                    no_of_islands++;
                }
            }
        }
        return no_of_islands;
    }
};