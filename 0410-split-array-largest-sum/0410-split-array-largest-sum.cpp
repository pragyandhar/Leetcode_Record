// TASKS
/*
1. Find out the range, max from the array and sum of the array
2. Apply the binary search on the range
3. Create a function to find out the subarray and if the division count == k then return true else false    
*/

class Solution {
public:
    bool isPossible(vector<int>& arr, int k, int mid) {
        int sum = 0;
        int count_groups = 1;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum > mid) {
                count_groups++;
                sum = arr[i];
            }
            if (count_groups > k) return false;
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        // Find out min and max
        int maxFind = 0;
        int sumFind = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxFind) {
                maxFind = nums[i];
            }
            sumFind += nums[i];
        }

        // Apply binary search on the range maxFind and sumFind.
        int res = -1;
        while (maxFind <= sumFind) {
            int mid = maxFind + (sumFind - maxFind)/2;
            if (isPossible(nums, k, mid)) {
                res = mid;
                sumFind = mid - 1;
            } else {
                maxFind = mid + 1;
            }
        }
        return res;
    }
};