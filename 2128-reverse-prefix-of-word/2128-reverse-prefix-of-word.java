class Solution {
    public String reversePrefix(String word, char ch) {
        // // --- Approach 1: Using character array (Better Solution) ---
        // // Convert string to char array for in-place manipulation
        // char[] charr = word.toCharArray();
        // int end = -1;
        // // Find first occurrence of ch
        // for (int a = 0; a < charr.length; a++) {
        //     if (charr[a] == ch) { 
        //         end = a; 
        //         break; 
        //     }
        // }
        // // If ch not found, return original string
        // if (end == -1) return word;
        // int start = 0;
        // int right = end;
        // // Reverse prefix from start to end using two pointers
        // while (start < right) {
        //     char temp = charr[start];
        //     charr[start] = charr[right];
        //     charr[right] = temp;
        //     start++;
        //     right--;
        // }
        // return new String(charr);

        // --- Approach 2: Using Java's inbuilt methods (Optimal Solution) ---
        // Find index of first occurrence of ch
        int index = word.indexOf(ch);
        // If ch not found, return original string
        if (index == -1) {
            return word;
        }
        // Extract prefix (up to ch) and suffix (after ch)
        String prefix = word.substring(0, index + 1);
        String suffix = word.substring(index + 1);
        // Reverse prefix and append suffix using StringBuilder
        String result = new StringBuilder(prefix).reverse().append(suffix).toString();
        return result.toString();
    }
}