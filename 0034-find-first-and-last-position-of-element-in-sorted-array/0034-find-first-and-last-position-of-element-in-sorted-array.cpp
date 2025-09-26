class Solution {
public:
    int findLeftMost(vector<int>& nums, int target, int n) {
        int s = 0;
        int e = n-1;
        int left_most = -1;
        while (s <= e) {
            int mid = s + (e-s)/2;
            if (target == nums[mid]) {
                left_most = mid;
                e = mid - 1;
            } else if (target > nums[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return left_most;
    }
    int findRightMost(vector<int>& nums, int target, int n) {
        int s = 0;
        int e = n-1;
        int right_most = -1;
        while (s <= e) {
            int mid = s + (e-s)/2;
            if (target == nums[mid]) {
                right_most = mid;
                s = mid + 1;
            } else if (target > nums[mid]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return right_most;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left_most = findLeftMost(nums, target, n);
        int right_most = findRightMost(nums, target, n);
        return {left_most, right_most};
    }
};