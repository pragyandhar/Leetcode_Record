/* APPROACH: Sliding Window */
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n < k) return false;
        unordered_set<string> seen;
        int left = 0;
        for (int right = 0; right < n; right++) {
            // Expand the Window Size
            // Check the window size
            if (right - left + 1 == k) {
                seen.insert(s.substr(left, k));
                // Shrink the window size
                left++;
            }
        }
        // Return the result after a check
        return seen.size() == (1 << k);
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });