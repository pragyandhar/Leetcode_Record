class Solution {
public:
    vector<string> str;
    int n;
    void helper(int index, string s) {
        // BASE CASE
        if (index == s.size()) {
            str.push_back(s);
            return;
        }
        // RECURSION
        if (isalpha(s[index])) {
            s[index] = tolower(s[index]); // Lowercase branch
            helper(index + 1, s);
            s[index] = toupper(s[index]); // Uppercase branch
            helper(index + 1, s);
        } else {
            helper
            (index + 1, s);
        }
    }
    vector<string> letterCasePermutation(string s) {
        helper(0, s);
        return str;
    }
};