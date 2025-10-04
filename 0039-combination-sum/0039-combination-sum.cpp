class Solution {
public:
    vector<vector<int>> ans;
    void helper(int index, vector<int>& cdts, vector<int>& curr, int t) {
        if (t == 0) {
            ans.push_back(curr);
            return;
        }
        if (index == cdts.size()) return;
        if (t >= cdts[index]) {
            curr.push_back(cdts[index]);
            helper(index, cdts, curr, t-cdts[index]);
            curr.pop_back();
        }
        helper(index+1, cdts, curr, t);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        helper(0, candidates, curr, target);
        return ans;
    }
};