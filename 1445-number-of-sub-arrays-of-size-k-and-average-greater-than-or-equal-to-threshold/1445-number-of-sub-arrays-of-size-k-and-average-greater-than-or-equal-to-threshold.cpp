/* APPROACH: Sliding Window */
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int count = 0; // Window State
        int sum = 0;
        int left = 0;
        for (int right = 0; right < n; right++) {
            // Expand
            sum += arr[right];
            // Check window size
            if (right - left + 1 == k) {
                if (sum / k >= threshold) {
                    count++;
                }
                // Shrink
                sum -= arr[left];
                left++;
            }
        }
        // Return the requirements
        return count;
    }
};