class Solution {
public:
    bool isPossible (vector<int>& nums, long long requiredTime, int totalTrips) {
        long long actualTrips = 0;

        for (int& i : nums) {
            actualTrips += requiredTime/i; // Total number of trips done by each bus
        }

        return actualTrips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();

        long long l = 0;
        long long r = (long long) *min_element(begin(time), end(time)) * totalTrips;

        while (l < r) {
            long long mid = l + (r-l)/2;
            if (isPossible(time, mid, totalTrips)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};