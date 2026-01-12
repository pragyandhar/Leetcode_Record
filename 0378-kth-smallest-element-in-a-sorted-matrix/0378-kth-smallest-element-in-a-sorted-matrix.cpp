class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // Max Heap Creation
        priority_queue<int> mxh;

        // Heap Container
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                mxh.push(matrix[i][j]);
                if (mxh.size() > k) {
                    mxh.pop();
                }
            }
        }
        return mxh.top();
    }
};