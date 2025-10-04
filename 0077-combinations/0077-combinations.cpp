class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int x, int n, int k, vector<int>& path) {
        if (k == 0) { 
            ans.push_back(path); 
            return; 
        }
        if (n - x + 1 < k) return;
        for (int i = x; i <= n; i++) {
            path.push_back(i);
            dfs(i+1, n, k-1, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        dfs(1, n, k, path);
        return ans;
    }
};
