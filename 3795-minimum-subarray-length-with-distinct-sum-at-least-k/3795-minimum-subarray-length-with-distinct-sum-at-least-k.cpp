class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();
        int count = INT_MAX;
        int sum = 0;
        unordered_map<int, int> mp;
        int left = 0;
    
        for (int right = 0; right < n; right++) {
            if (mp[nums[right]]==0) {
                sum+=nums[right];
            }
            mp[nums[right]]++;
            while (sum >=k) {
                count =min(count, right - left + 1);
                mp[nums[left]]--;
                if (mp[nums[left]]== 0) {
                    sum -= nums[left];
                }
                left++;
            }
        }
        return (count == INT_MAX)?-1 :count;
    }
};