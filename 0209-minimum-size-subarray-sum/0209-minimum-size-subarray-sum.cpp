class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0; 
        int left = 0;
        int minLen = INT_MAX;
        for (int right = 0; right < nums.size(); right++) {
            // EXPAND
            sum += nums[right];
            // CHECK CONDITION TO REDUCE WINDOW SIZE
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};