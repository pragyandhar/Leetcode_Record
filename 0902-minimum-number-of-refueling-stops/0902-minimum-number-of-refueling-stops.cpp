class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();

        priority_queue<int> maxHeap;
        int idx = 0, fuel = startFuel, stop = 0;

        while (fuel < target) {
            while (idx < n && stations[idx][0] <= fuel) {
                maxHeap.push(stations[idx][1]);
                idx++;
            }
            if (maxHeap.empty()) return -1;
            fuel += maxHeap.top();
            maxHeap.pop();
            stop++;
        }
        return stop;
    }
};