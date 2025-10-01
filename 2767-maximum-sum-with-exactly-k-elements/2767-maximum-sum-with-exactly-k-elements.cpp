class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int a = nums[n-1];
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += a;
            a++;
        }
        return sum;
    }
};