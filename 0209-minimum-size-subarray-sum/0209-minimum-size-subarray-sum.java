/* BRUTE FORCE APPROACH: Brute Force - O(n2) */
// class Solution {
//     public int minSubArrayLen(int target, int[] nums) {
//         int n = nums.length;
//         int minLen = Integer.MAX_VALUE;
//         for (int i = 0; i < n; i++) {
//             int sum = 0;
//             for (int j = i; j < n; j++) {
//                 sum += nums[j];
//                 if (sum >= target) {         
//                     minLen = Math.min(minLen, j - i + 1);
//                     break;                  
//                 }
//             }
//         }
//         return (minLen == Integer.MAX_VALUE) ? 0 : minLen;
//     }
// }

/* OPTIMAL APPROACH: Sliding Window - O(n) */
// class Solution {
//     public int minSubArrayLen(int target, int[] nums) {
//         int minLen = Integer.MAX_VALUE;
//         int sum = 0;
//         int left = 0;

//         for (int right = 0; right < nums.length; right++) {
//             sum += nums[right];
            
//             while (sum >= target) {
//                 minLen = Math.min(minLen, right - left + 1);
//                 sum -= nums[left];
//                 left++;
//             }
//         }
//         return minLen == Integer.MAX_VALUE ? 0 : minLen;
//     }
// }

/* BETTER APPROACH: Binary Search over Prefix Sum - O(nlogn) + O(n) */
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        long[] prefix = new long[n + 1];

        // Build prefix sum array
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        int minLen = Integer.MAX_VALUE;

        // For each i, the rightmost j where prefix[j] <= prefix[i] - target
        for (int i = 1; i <= n; i++) {
            long need = prefix[i] - target;

            int j = binarySearch(prefix, i - 1, need);
            if (j != -1) {
                minLen = Math.min(minLen, i - j);
            }
        }

        return (minLen == Integer.MAX_VALUE) ? 0 : minLen;
    }

    // Binary search to find largest j where prefix[j] <= need
    private int binarySearch(long[] prefix, int high, long need) {
        int low = 0, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (prefix[mid] <= need) {
                ans = mid;      
                low = mid + 1;  
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
}
