class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } 
            else if (!st.empty()) {
                if (st.top() == '(' && s[i] == ')') {
                    st.pop();
                }
            } 
            else { // When stack is empty
                count += 1;
            }
        }
        count += (int)st.size();
        return count;
    }
};