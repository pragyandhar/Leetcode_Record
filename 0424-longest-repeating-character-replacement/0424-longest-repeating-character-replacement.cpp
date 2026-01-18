class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int freq[256] = {0};
        int maxFreq = INT_MIN;
        int ans = INT_MIN;
        int left = 0;
        for (int right = 0; right < n; right++) {
            // EXPAND
            freq[s[right]]++;
            maxFreq = max(maxFreq, freq[s[right]]);
            // SHRINK
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left]]--;
                left++;
            }
            // UPDATE
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};