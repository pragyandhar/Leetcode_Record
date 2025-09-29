/* APPROACH: Sliding Window */
class Solution {
public:
    bool isVowel (char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        if (n < k) return false;
        int count = 0;
        int maxCount = 0; // Window State
        int left = 0;
        for (int right = 0; right < n; right++) {
            // Expand the Window Size
            if (isVowel(s[right])) count++;
            // Check the window size
            if (right - left + 1 == k) {
                maxCount = max(count, maxCount);
                // Shrink the window size
                if (isVowel(s[left])) count--;
                left++;
            }
        }
        // Return the requirement
        return maxCount;
    }
};