class Solution {
    public int search(int[] nums, int target) {
        int i = 0;
        int low = 0;
        int high = nums.length-1;
        while (low <= high) {
            int mid = low + (high-low) / 2;
            // < Condition
            if (target < nums[mid]) {
                high = mid - 1;
            } 
            // > Condition
            if(target > nums[mid]) {
                low = mid + 1;
            }
            // == Condition
            if (target == nums[mid]) {
                return mid;
            }
        }
        return -1;
    }
}