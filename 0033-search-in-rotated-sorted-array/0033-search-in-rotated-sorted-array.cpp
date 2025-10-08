/*
class Solution {
public:
    int findPivot(vector<int>& nums, int n) {
        int s = 0;
        int e = n-1;

        while (s < e) {
            int mid = s + (e-s)/2;
            if (nums[mid] > nums[e]) s = mid + 1;
            else e = mid;
        }
        return e;
    }

    int BS(int s, int e, vector<int>& nums, int target) {
        int idx = -1;
        while (s <= e) {
            int mid = s + (e-s)/2;
            if (target == nums[mid]) {
                idx = mid;
                break;
            } else if (nums[mid] < target) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return idx;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot_index = findPivot(nums, n);
        int idx = BS(0, pivot_index-1, nums, target);
        if (idx != -1) {
            return idx;
        }
        idx = BS(pivot_index, n-1, nums, target);
        return idx;
    }
};
*/

class Solution {
public:
    int findPivot(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) low = mid + 1;
            else high = mid;
        }
        return low;
    }
    int BinarySearch(vector<int>& nums, int target, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = findPivot(nums);

        int left = BinarySearch(nums, target, 0, pivot-1);
        if (left != -1) return left;

        return BinarySearch(nums, target, pivot, n-1);
    }
};