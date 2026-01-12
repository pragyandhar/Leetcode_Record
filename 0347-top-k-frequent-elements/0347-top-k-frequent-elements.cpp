class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Frequency Counting
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;
        // Heap Containerisation
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;

        for (auto& it: freq){
            // 1. Push
            minh.push({it.second, it.first});
            // 2. Size Check and Pop
            if (minh.size() > k) {
                minh.pop();
            }
        }
        // Returning the answer
        vector<int> ans;
        while (!minh.empty()) {
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};