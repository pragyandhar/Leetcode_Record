class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int leftPtr = 0;
        int k = 3; // Fixed window size as per the question
        int count = 0;
        unordered_map<char, int> freq; // A window state: information we need about the current substring

        for (int rightPtr = 0; rightPtr < n; rightPtr++) {
            // Expand the Window
            freq[s[rightPtr]]++;
            // Check the window size
            if (rightPtr - leftPtr + 1 == k) {
                if (freq.size() == k) {
                    count++;
                }
                // Shrink the window size
                freq[s[leftPtr]]--;
                if (freq[s[leftPtr]] == 0) {
                    freq.erase(s[leftPtr]);
                }
                leftPtr++;
            }
        }
        // Return the answer
        return count;
    }
};