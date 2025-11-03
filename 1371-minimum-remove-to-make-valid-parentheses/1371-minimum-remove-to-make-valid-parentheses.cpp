class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> remove_indices;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') { // When stack may or may not be empty
                st.push(i);
            } 
            else if (s[i] == ')') { 
                if (!st.empty()) {
                    st.pop();
                } else {
                    remove_indices.insert(i);
                }
            } 
        }
        while (!st.empty()) {
            remove_indices.insert(st.top());
            st.pop();
        }
        
        string str;
        for (int i = 0; i < s.size(); i++) {
            if (remove_indices.count(i) == 0) {
                str += s[i];
            }
        }
        return str;
    }
};