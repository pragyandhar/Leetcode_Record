class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int>& nums, vector<int>& curr, vector<int>& used) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;   // If in use then skip
            used[i] = 1;             // Mark
            curr.push_back(nums[i]); // Add it to current
            helper(nums, curr, used);// Recursive Call
            curr.pop_back();
            used[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> used(nums.size(), 0);
        vector<int> curr;
        helper(nums, curr, used);
        return ans;
    }
};