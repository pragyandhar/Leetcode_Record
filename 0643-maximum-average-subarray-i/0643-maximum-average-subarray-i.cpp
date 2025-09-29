/* APPROACH: Sliding Window */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return nums[0];
        long long sum = 0;
        long long maxSum = LLONG_MIN;
        int left = 0;
        for (int right = 0; right < n; right++) {
            // Expand the window size
            sum += nums[right];
            // Check the window size
            if (right - left + 1 == k) {
                maxSum = max(sum, maxSum);
                // Shrink the window size
                sum -= nums[left];
                left++;
            }
        }
        // Return the requirements
        return (double) maxSum/k;
    }
};