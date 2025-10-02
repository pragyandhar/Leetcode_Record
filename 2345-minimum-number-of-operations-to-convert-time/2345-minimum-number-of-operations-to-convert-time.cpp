class Solution {
public:
    int convertTime(string current, string correct) {
        auto getMin = [](string t) {
            return stoi(t.substr(0,2)) * 60 + stoi(t.substr(3,2));
        };
        int curr = getMin(current);
        int corr = getMin(correct);
        int diff = corr - curr;
        int ops = 0;
        vector<int> steps = {60,15,5,1};
        for (int s : steps) {
            ops += diff / s;
            diff %= s;
        }
        return ops;
    }
};