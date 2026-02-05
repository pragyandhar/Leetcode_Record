class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        // Write your logic here
        stack<int> s;
        for (int x : a) {
            bool flag = 0;
            while (!s.empty() && (s.top() > 0  &&  x < 0)) {
                // If the one in the stack is smaller than the one in the array
                if (s.top() < abs(x)) {
                    s.pop();
                }

                // If the one in the stack is same as the one in the array
                else if (s.top() == abs(x)) {
                    s.pop();
                    flag = 1;
                    break;
                }

                // If both the asteroids are moving on the same direction
                else {
                    flag = 1;
                    break;
                }
            }
            if (!flag) s.push(x);
        }
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};