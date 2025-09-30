/* APPROACH: Sliding Window */
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSize = 2 * k + 1;
        vector<int> result(n, -1);
        if (n < windowSize) return result;
        long long sum = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            // Expand
            sum += nums[right];
            // Check the window size
            if (right - left + 1 == windowSize) {
                int center = left + k;
                result[center] = sum / windowSize;
                // Shrink
                sum -= nums[left];
                left++;
            }
        }
        // Return the requirement
        return result;
    }
};