/* DYNAMIC SIZE SLIDING WINDOW */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int ans = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            // EXPAND
            freq[s[right]]++;
            // SHRINK
            while (freq[s[right]] > 1) {
                freq[s[left]]--;
                left++;
            }
            // UPDATE
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};