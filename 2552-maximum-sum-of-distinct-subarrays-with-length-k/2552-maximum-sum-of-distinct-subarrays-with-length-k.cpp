class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long windowSum = 0;
        unordered_map<int, int> freq;
        long long maxSum = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            // Expand the window size
            windowSum += nums[right];
            freq[nums[right]]++;
            // Check the window size
            if (right - left + 1 == k) {
                if (freq.size() == k) {
                    maxSum = max(maxSum, windowSum);
                }
                // Shrink the window size
                windowSum -= nums[left];
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }
        }
        // Return the requirement
        return maxSum;
    }
};