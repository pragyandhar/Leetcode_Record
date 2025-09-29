class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();

        if (n < k) return {};
        
        vector<int> result;

        unordered_map<char, int> sCount, pCount;
        for (char c : p) pCount[c]++;

        int left = 0;
        for (int right = 0; right < n; right++) {
            // Expand the Window
            sCount[s[right]]++;
            // Check the window size
            if (right - left + 1 == k) {
                if (sCount == pCount) {
                    result.push_back(left);
                }
                // Shrink the window
                sCount[s[left]]--;
                if (sCount[s[left]] == 0) {
                    sCount.erase(s[left]);
                }
                left++;
            }
        }
        // Return the result
        return result;
    }
};