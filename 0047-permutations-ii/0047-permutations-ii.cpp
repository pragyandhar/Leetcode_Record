/* METHOD-1: Used Array Based */
// class Solution {
// public:
//     vector<vector<int>> ans;
//     void helper(vector<int>& nums, vector<int>& curr, vector<int>& used) {
//         if (curr.size() == nums.size()) {
//             ans.push_back(curr);
//             return;
//         }
//         for (int i = 0; i < nums.size(); i++) {
//             if (used[i]) continue;

//             if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

//             used[i] = 1;
//             curr.push_back(nums[i]);
//             helper(nums, curr, used);
//             curr.pop_back();
//             used[i] = 0;
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<int> curr;
//         vector<int> used(nums.size(), 0);
//         helper(nums, curr, used);
//         return ans;
//     }
// };

/* METHOD-2: Swap Based */
class Solution {
public:
    vector<vector<int>> ans;
    void helper(int index, vector<int>& nums) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> seen;

        for (int i = index; i < nums.size(); i++) {
            if (seen.count(nums[i])) continue;
            seen.insert(nums[i]);

            swap(nums[index], nums[i]);
            helper(index + 1, nums);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        helper(0, nums);
        return ans;
    }
};