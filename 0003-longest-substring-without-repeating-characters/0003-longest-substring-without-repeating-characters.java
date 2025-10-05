class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] freq = new int[256];
        Arrays.fill(freq, 0);
        int maxLen = 0;
        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            // EXPAND
            freq[s.charAt(right)]++;
            // SHRINK WHILE INVALID
            while (freq[s.charAt(right)] > 1) {
                freq[s.charAt(left)]--;
                left++;
            }
            // UPDATE THE ANSWER
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }
}