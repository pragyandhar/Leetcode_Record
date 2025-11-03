// class Solution {
// public:
//     string removeOuterParentheses(string s) {
//         stack<char> st;
//         string res = "";
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '(') {
//                 if (!st.empty()) res += s[i]; 
//                 st.push(s[i]);
//             } else {
//                 st.pop();
//                 if (!st.empty()) res += s[i];
//             } 
//         }
//         return res;
//     }
// };

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int depth = 0;  // track current level of nesting
        for (char c : s) {
            if (c == '(') {
                // if depth > 0, it means it's not the outermost '('
                if (depth > 0) result += c;
                depth++;
            } else { // c == ')'
                depth--;
                // if depth > 0 after decrement, it's not the outermost ')'
                if (depth > 0) result += c;
            }
        }
        return result;
    }
};