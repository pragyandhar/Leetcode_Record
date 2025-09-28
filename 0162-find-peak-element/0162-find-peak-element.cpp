class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int ans = *max_element(nums.begin(), nums.end());
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == ans) idx = i;
        }
        return idx;
    }
};