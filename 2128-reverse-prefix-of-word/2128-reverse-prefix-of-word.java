class Solution {
    public String reversePrefix(String word, char ch) {
        char[] charr = word.toCharArray();
        int start = 0;
        int end = 0;
        for (int a = 0; a < charr.length; a++) {
            if (charr[a] == ch) { end = a; break; }
        }
        while (start <= end) {
            char temp = charr[start];
            charr[start] = charr[end];
            charr[end] = temp;

            start++;
            end--;
        }
        return new String(charr);
    }
}