/* APPROACH: Sliding Window */
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;
        map<int, int> freq;
        int left = 0;

        for (int right = 0; right < n; right++) {
            // Extend
            if (nums[right] < 0) {
                freq[nums[right]]++;
            }
            // Check window size
            if (right - left + 1 == k) {
                int count = 0;
                int val = 0;
                for (auto &it: freq) {
                    count += it.second;
                    if (count >= x) {
                        val = it.first;
                        break;
                    }
                }
                result.push_back(val);
                // Shrink
                if (nums[left] < 0) {
                    freq[nums[left]]--;
                    if (freq[nums[left]] == 0) {
                        freq.erase(nums[left]);
                    }
                }
                left++;
            }
        }
        // Return the Requirements
        return result;
    }
};