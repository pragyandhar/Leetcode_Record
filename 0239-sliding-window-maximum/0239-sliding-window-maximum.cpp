class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        deque<int> dq;
        vector<int> ans;
        int left = 0;
        for (int right = 0; right < n; right++) {
            // EXPAND
            while (!dq.empty() && dq.back() < arr[right]) dq.pop_back();
            dq.push_back(arr[right]);
            // CHECK WINDOW SIZE
            if (right - left + 1 == k) {
                ans.push_back(dq.front());
                // SHRINK
                if (dq.front() == arr[left]) {
                    dq.pop_front();
                }
                left++;
            }
        }
        return ans;
    }
};