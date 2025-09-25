class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (int i = 1; i <= nums.size()-1; i++) {
            nums[i] = nums[i-1] + nums[i];
        }
        return nums;
    }
};