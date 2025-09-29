class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size()-1;
        int col = grid[0].size()-1;
        int row = 0;
        while (row <= m && col >= 0) {
            if (grid[row][col] >= 0) {
                row++;
            } else {
                count += grid.size()-row;
                col--;
            }
        }
        return count;
    }
};