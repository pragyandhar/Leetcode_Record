class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = {-1, -1};
        int left = LEFT(nums, target);
        int right = RIGHT(nums, target);
        ans[0] = left;
        ans[1] = right;
        return ans;
    }
    public int LEFT(int[] arr, int target) {
        int low = 0;
        int high = arr.length-1;
        int first = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // == condition
            if (arr[mid] == target) {
                first = mid;
                high = mid - 1;
            }
            // < condition
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            // > condition
            else {
                high = mid - 1;
            }
        }
        return first;
    }

    public int RIGHT(int[] arr, int target) {
        int low = 0;
        int high = arr.length - 1;
        int last = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // == condition
            if (arr[mid] == target) {
                last = mid;
                low = mid + 1;
            }
            // < condition
            else if (arr[mid] < target) {
                low = mid + 1;
            }
            // > condition
            else {
                high = mid - 1;
            }
        }
        return last;
    }
}