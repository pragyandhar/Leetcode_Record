/*
1. Find the total sum of the subarray
2. Find the minimum subarray sum using Kadene's Algorithm
3. Find the maximum subarray sum using Kadene's Algorithm
4. Find the circular subarray sum = Total Sum - Minimum Subarray Sum
5. Apply a check for {-1,-1,-1} that it should return -1 and not 0
*/

class Solution {
public:
    int TotalSumOfArray(vector<int>& arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];        
        }
        return sum;
    }
    int Kadene_Min(vector<int>& arr) {
        int global = arr[0];
        int curr = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            curr = min(arr[i], curr+arr[i]);
            global = min(curr, global);
        }
        return global;
    }
    int Kadene_Max(vector<int>& arr) {
        int global = arr[0];
        int curr = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            curr = max(arr[i], curr + arr[i]);
            global = max(global, curr);
        }
        return global;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int sum = TotalSumOfArray(nums);
        int min = Kadene_Min(nums);
        int max = Kadene_Max(nums);
        int circularSum = sum - min;

        if (max > 0) {
            return std::max(max, circularSum);
        }
        else return max;
    }
};