class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 1. Sort
        sort(people.begin(), people.end(), 
            [](const auto& a, const auto& b) {
                if(a[0] == b[0]) return a[1] < b[1];
                return a[0] > b[0];
            }
        );
        // 2. Make a Vector
        vector<vector<int>> ans;
        // 3. Insert {} at kth index
        for (auto &x : people) {
            ans.insert(ans.begin() + x[1], x);
        }
        return ans;
    }
};