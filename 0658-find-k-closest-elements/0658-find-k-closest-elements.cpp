class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Comparator to check the conditions
        auto cmp = [&] (int a, int b) {
            int da = abs(a-x);
            int db = abs(b-x);
            if (da != db) return da < db;
            return a < b;
        };
        // Making the Heap
        priority_queue<int, vector<int>, decltype(cmp)> maxh(cmp);
        // Heap containerisation
        for (int val : arr) {
            maxh.push(val);
            if (maxh.size() > k) maxh.pop();
        }
        // Return the answer
        vector<int> ans;
        while (!maxh.empty()) {
            ans.push_back(maxh.top());
            maxh.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};