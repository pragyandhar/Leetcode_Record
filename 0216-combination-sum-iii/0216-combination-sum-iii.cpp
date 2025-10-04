class Solution {
public:
    vector<vector<int>> ans;
    void helper(int index, int n, int k, vector<int>& arr, vector<int>& curr) {
        if (n == 0 && curr.size() == k){
            ans.push_back(curr);
            return;
        }
        if (index == arr.size()) return;
        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i-1]) continue;
            if (!curr.empty() || n >= arr[i]) {
                curr.push_back(arr[i]);
                helper(i+1, n-arr[i], k, arr, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr(9);
        for (int i = 0; i < 9; i++) {
            arr[i] = i + 1;
        }
        vector<int> curr;
        helper(0, n, k, arr, curr);
        return ans;
    }
};