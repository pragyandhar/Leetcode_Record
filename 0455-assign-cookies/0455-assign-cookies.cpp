/* GREEDY ALGORITHM */
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // STEP - 1: Sort the arrays as smallest cookie that could satisfy a child should be given
        sort(begin(g), end(g));
        sort(begin(s), end(s));

        int i = 0;
        int j = 0;
        int count = 0;

        // STEP - 2: Decision Rule
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        // STEP - 3: Return the result
        return count;
    }
};