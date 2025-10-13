/* APPROACH: Sliding Window */
import java.util.*;

class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n = s2.length();
        int k = s1.length();

        boolean flag = false;

        Map<Character, Integer> s1Count = new HashMap<>();
        Map<Character, Integer> s2Count = new HashMap<>();
        for (char ch : s1.toCharArray()) s1Count.put(ch, s1Count.getOrDefault(ch, 0) + 1);

        int left = 0;
        for (int right = 0; right < n; right++) {
            // Expand the window
            s2Count.put(s2.charAt(right), s2Count.getOrDefault(s2.charAt(right), 0) + 1);

            // Check the window size
            if (right - left + 1 == k) {
                if (s1Count.equals(s2Count)) {
                    flag = true;
                }
                // Shrink the Window Size
                char leftChar = s2.charAt(left);
                s2Count.put(leftChar, s2Count.get(leftChar) - 1);
                if (s2Count.get(leftChar) == 0) {
                    s2Count.remove(leftChar);
                }
                left++;
            }
        }
        // Return the result
        return flag;
    }
}
