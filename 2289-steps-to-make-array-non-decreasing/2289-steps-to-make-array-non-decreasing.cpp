class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int,int>> s;
        int ans = 0;

        for (int x : nums) {
            int steps = 0;

            while (!s.empty() && s.top().first <= x) {
                steps = max(steps, s.top().second);
                s.pop();
            }

            if (!s.empty()) steps++;

            ans = max(ans, steps);
            s.push({x, steps});
        }

        return ans;
    }
};