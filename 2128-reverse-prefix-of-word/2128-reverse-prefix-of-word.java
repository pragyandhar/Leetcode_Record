class Solution {
    public String reversePrefix(String word, char ch) {
        char[] charr = word.toCharArray();
        int end = -1;
        for (int a = 0; a < charr.length; a++) {
            if (charr[a] == ch) { end = a; break; }
        }
        if (end == -1) return word;
        int start = 0;
        int right = end;
        while (start < right) {
            char temp = charr[start];
            charr[start] = charr[right];
            charr[right] = temp;

            start++;
            right--;
        }
        return new String(charr);
    }
}