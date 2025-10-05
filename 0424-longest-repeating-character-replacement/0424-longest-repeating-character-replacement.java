class Solution {
    public int characterReplacement(String s, int k) {
        int[] freq = new int[256];
        Arrays.fill(freq, 0);
        int maxFreq = 0;
        int maxLen = 0;
        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            // EXPAND
            freq[s.charAt(right)]++;
            maxFreq = Math.max(maxFreq, freq[s.charAt(right)]);

            // CHECK CONDITION
            while (right - left + 1 - maxFreq > k) {
                freq[s.charAt(left)]--;
                left++;
            }
 
            // UPDATE
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }
}