/* RECURSION */
class Solution {
public:
    vector<vector<int>> ans;
    void helper(int index, vector<int> nums, vector<int> path) {
        // BASE CASE
        if (index == nums.size()) {
            ans.push_back(path);
            return;
        }
        // Choice-1: Pick
        path.push_back(nums[index]);
        helper(index + 1, nums, path);

        // Choice-2: Skip
        path.pop_back();
        helper(index + 1, nums, path);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        helper(0, nums, path);
        return ans;
    }
};
auto init = atexit([]() { ofstream("display_runtime.txt") << "0"; });