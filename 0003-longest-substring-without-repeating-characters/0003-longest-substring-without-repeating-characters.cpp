class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256, 0);
        int maxLen = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            // Expand
            freq[s[right]]++;
            // Shrink while invalid
            while (freq[s[right]] > 1) {
                freq[s[left]]--;
                left++;
            }
            // Update the answer
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};