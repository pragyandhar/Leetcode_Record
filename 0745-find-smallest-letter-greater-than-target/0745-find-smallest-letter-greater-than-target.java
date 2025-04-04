class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int low = 0;
        int high = letters.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // > Condition
            if (letters[mid] > target) {
                high = mid - 1;
            }
            // < Condition
            if (letters[mid] <= target) {
                low = mid + 1;
            }
        }
        return letters[low % letters.length];
    }
}