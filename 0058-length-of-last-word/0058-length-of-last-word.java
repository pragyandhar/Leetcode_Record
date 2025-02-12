class Solution {
    public int lengthOfLastWord(String s) {
        // Trim spaces
        s = s.trim(); 
        
        // Split by spaces
        String[] words = s.split(" ");
        
        // Get the last word and return its length
        return words[words.length - 1].length();
    }
}
