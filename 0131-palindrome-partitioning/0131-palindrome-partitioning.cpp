class Solution {
public:
    vector<vector<string>> ans;
    int n;
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    void helper(int index, string& s, vector<string>& curr) {
        n = s.size();
        if (index == n) {
            ans.push_back(curr);
        }
        for (int i = index; i < n; i++) {
            if (isPalindrome(s, index, i)){
                curr.push_back(s.substr(index, i-index+1));
                helper(i+1, s, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        helper(0, s, curr);
        return ans;
    }
};