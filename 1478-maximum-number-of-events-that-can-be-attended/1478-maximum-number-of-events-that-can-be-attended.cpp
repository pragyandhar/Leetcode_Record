class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int idx = 0, day = 0, attended = 0;
        while (idx < n || !minHeap.empty()) {
            if (minHeap.empty()) {
                day = events[idx][0];
            }
            while (idx < n && events[idx][0] == day) {
                minHeap.push(events[idx][1]);
                idx++;
            }
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }
            if (!minHeap.empty()) {
                minHeap.pop();
                attended++;
                day++;
            } else {
                day++;
            }
        }
        return attended;
    }
};