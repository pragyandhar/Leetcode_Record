class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void helper(int index, vector<int> nums, vector<int> curr) {
        if (curr.size() >= 2) {
            ans.push_back(curr);
        }
        unordered_set<int> st;
        for (int i = index; i < n; i++) {
            if (!curr.empty() && curr.back() > nums[i]) continue; // Checks if element breaks the root condition of the question, non-decreasing sequence
            if (st.count(nums[i])) continue; // Checks if the set has the element in it before hand
            st.insert(nums[i]);

            curr.push_back(nums[i]);
            helper(i + 1, nums, curr);
            curr.pop_back();
        }

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> curr;
        helper(0, nums, curr);
        return ans;
    }
};