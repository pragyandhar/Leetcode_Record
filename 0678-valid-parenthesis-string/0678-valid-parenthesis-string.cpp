class Solution {
public:
    bool checkValidString(string s) {
        int hi = 0;
        int lo = 0;

        for (char c : s) {
            if (c == '(') {
                lo++;
                hi++;
            } else if (c == ')') {
                lo = max(0, lo-1);
                hi--;
            } else {
                lo = max(0, lo-1);
                hi++;
            }
            if (hi < 0) return false;
        }
        return (lo == 0);
    }
};