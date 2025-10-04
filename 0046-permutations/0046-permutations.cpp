class Solution {
public:
    vector<vector<int>> ans;
    // void helper(vector<int>& nums, vector<int>& curr, vector<int>& used) {
    //     if (curr.size() == nums.size()) {
    //         ans.push_back(curr);
    //         return;
    //     }
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (used[i]) continue;   // If in use then skip
    //         used[i] = 1;             // Mark
    //         curr.push_back(nums[i]); // Add it to current
    //         helper(nums, curr, used);// Recursive Call
    //         curr.pop_back();         // Unmark it - Backtrack
    //         used[i] = 0;
    //     }
    // }

    void helper(int index, vector<int>& nums) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            helper(index + 1, nums);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<int> used(nums.size(), 0);
        // vector<int> curr;
        // helper(nums, curr, used);
        // return ans;
        helper(0, nums);
        return ans;
    }
};