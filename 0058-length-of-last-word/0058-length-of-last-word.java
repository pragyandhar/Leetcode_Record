class Solution {
    public int lengthOfLastWord(String s) {
        // Step 1: Trim any leading or trailing spaces from the input string
        String str = s.trim();
        
        // Step 2: Initialize a counter to keep track of the last word's length
        int count = 0;
        
        // Step 3: Iterate from the last character of the trimmed string to the beginning
        for (int i = str.length() - 1; i >= 0; i--) {
            // If the current character is not a space, increment the count
            if (str.charAt(i) != ' ') {
                count++;
            } else {
                // If a space is encountered after counting some characters, break the loop
                break;
            }
        }
        
        // Step 4: Return the length of the last word
        return count;
    }
}
