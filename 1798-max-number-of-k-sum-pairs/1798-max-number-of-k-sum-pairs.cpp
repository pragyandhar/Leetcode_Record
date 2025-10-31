/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 */

// @lc code=start
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int i = 0;
        int j = size(nums)-1;
        int operations = 0;
        sort(nums.begin(), nums.end());
        while (i < j) {
            int sum = nums[i] + nums[j];
            if (sum == k) {
                i++;
                j--;
                operations++;
            } else if (sum > k) {
                j--;
            } else {
                i++;
            }
        }
        return operations;
    }
};
// @lc code=end

