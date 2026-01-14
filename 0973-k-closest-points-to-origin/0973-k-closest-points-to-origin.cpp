class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max-Heap Making
        priority_queue<pair<long long, int>> maxh;
        // Heap Containerisation
        for (int i = 0; i < points.size(); i++) {
            long long distance = 1LL * points[i][0] * points[i][0] + 1LL * points[i][1] * points[i][1];
            maxh.push({distance, i});
            if (maxh.size() > k) maxh.pop();
        }

        // Store the answer
        vector<vector<int>> ans;
        while (!maxh.empty()) {
            ans.push_back(points[maxh.top().second]);
            maxh.pop();
        }

        return ans;
    }
};