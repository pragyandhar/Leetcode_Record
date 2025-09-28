/*
1.Sort the array
     (i) Most negative numbers will be at the end
    (ii) Most Positive numbers will be at the beginning
2. Calculate two possible products
     (i) Product of the three largest positive integers
    (ii) Product of the two smallest negative and one largest positive integer
3. Return the maximum of the two products
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        // 1. Sort the array
        sort(nums.begin(), nums.end());
        // 2. Calculate two possible products
        int a = nums[n-1] * nums[n-2] * nums[n-3]; // All positive numbers
        int b = nums[0] * nums[1] * nums[n-1]; // Two negative and one positive
        // 3. Return the maximum of the two products
        return max(a, b);
    }
};