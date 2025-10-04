class Solution {
public:
    vector<vector<int>> ans;
    void helper(int index, int target, vector<int>& candidates, vector<int>& curr) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        if (index == candidates.size()) return;
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i-1]) continue;
            if (target >= candidates[i]) {
                curr.push_back(candidates[i]);
                helper(i+1, target - candidates[i], candidates, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        helper(0, target, candidates, curr);
        return ans;
    }
};