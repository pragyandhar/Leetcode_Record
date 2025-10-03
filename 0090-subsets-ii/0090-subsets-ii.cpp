class Solution {
public:
    vector<vector<int>> ans;
    void helper(int start, vector<int> nums, vector<int> path) {
        ans.push_back(path);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            path.push_back(nums[i]);
            helper(i+1, nums, path);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        helper(0, nums, path);
        return ans;
    }
};