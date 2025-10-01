class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxEl = *max_element(nums.begin(), nums.end());
        int lastEl = maxEl + k - 1;
        int sum = k * (maxEl + lastEl) / 2;
        return sum;
    }
};