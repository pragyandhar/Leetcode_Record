class Solution {
    public int sumOfPower(int[] nums) {
        long MOD = 1_000_000_007L;
        Arrays.sort(nums);

        long ans = 0;
        long prefix = 0;

        for (long x : nums) {
            long x2 = (x * x) % MOD;

            ans = (ans + x2 * prefix) % MOD; // with previous mins
            ans = (ans + x2 * x) % MOD;      // single element

            prefix = (prefix * 2 + x) % MOD;
        }
        return (int) ans;
    }
}
