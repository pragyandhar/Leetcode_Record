/* APPROACH: Sliding Window */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int k = s1.size();

        bool flag = false;

        unordered_map<char, int> s1Count, s2Count;
        for (char ch : s1) s1Count[ch]++;

        int left = 0;
        for (int right = 0; right < n; right++) {
            // Expand the window
            s2Count[s2[right]]++;
            // Check the window size
            if (right - left + 1 == k) {
                if (s1Count == s2Count) {
                    flag = true;
                }
                // Shrink the Window Size
                s2Count[s2[left]]--;
                if (s2Count[s2[left]] == 0) {
                    s2Count.erase(s2[left]);
                }
                left++;
            }
        }
        // Return the result
        return flag;
    }
};