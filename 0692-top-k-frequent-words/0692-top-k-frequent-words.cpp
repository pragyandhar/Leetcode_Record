class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Frequency Counting
        unordered_map<string, int> freq;
        for (auto& x : words) freq[x]++;
        // Heap Containerisation
        auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> minh(cmp);

        for (auto& it : freq) {
            minh.push({it.second, it.first});
            if (minh.size() > k) minh.pop();
        }

        vector<string> ans;
        while (!minh.empty()) {
            ans.push_back(minh.top().second);
            minh.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};