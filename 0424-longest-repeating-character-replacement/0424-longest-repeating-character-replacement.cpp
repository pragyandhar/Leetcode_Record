class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(256, 0);
        int maxFreq = 0;
        int maxLen = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            // EXPAND
            freq[s[right]]++;
            maxFreq = max(maxFreq, freq[s[right]]);

            // CHECK CONDITION TO SHRINK
            while (right - left + 1 - maxFreq > k) {
                freq[s[left]]--;
                left++;
            }

            // UPDATE THE ANSWER
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};