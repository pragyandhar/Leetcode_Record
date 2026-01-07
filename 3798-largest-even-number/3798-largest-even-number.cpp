class Solution {
public:
    string largestEven(string s) {
        while (!s.empty() && s.back() != '2') {
            s.pop_back();
        }
        return s;
    }
};