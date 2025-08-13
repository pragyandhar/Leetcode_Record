class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;

        // Edge Cases
        if (n == 0) return;
        k %= n;
        if (k == 0) return;

        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }

    private void reverse(int[] a, int l, int m) {
        while (l < m) {
            int temp = a[l];
            a[l] = a[m];
            a[m] = temp;
            l++;
            m--;
        }
    }
}