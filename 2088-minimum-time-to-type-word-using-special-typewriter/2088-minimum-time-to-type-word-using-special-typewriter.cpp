class Solution {
public:
    int minTimeToType(string word) {
        int time = 0;
        char curr = 'a';
        for (char ch : word) {
            int diff = abs(ch - curr);
            int moveCost = min(diff, 26-diff);
            time += moveCost + 1;
            curr = ch;
        }
        return time;
    }
};