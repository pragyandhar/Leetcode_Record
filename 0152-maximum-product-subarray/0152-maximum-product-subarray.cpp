/*
1. Start fresh with each element of the array
2. Track the previous maximum and previous minimum and update it with the current value
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n   = nums.size();
        int ans = nums[0]; // Global Maximum
        int f   = nums[0]; // Tracks previous Maximum till the index
        int g   = nums[0]; // Tracks previous Minimum till the index

        for (int i = 1; i < n; i++) {
            int prevMax = f; // Storing them because we need it for calculation
            int prevMin = g; // Storing them because we need it for calculation

            f = max({nums[i], prevMax * nums[i], prevMin * nums[i]});
            g = min({nums[i], prevMax * nums[i], prevMin * nums[i]});

            ans = max(ans, f);
        }
        
        return ans;
    }
};