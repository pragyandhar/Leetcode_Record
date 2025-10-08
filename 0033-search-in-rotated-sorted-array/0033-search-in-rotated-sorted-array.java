class Solution {
    public int findPivot(int[] n) {
        int low = 0;
        int high = n.length-1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (n[mid] > n[high]) low = mid + 1;
            else high = mid;
        }

        return low;
    } 

    public int BS(int[] n, int t, int low, int high) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (n[mid] == t) return mid;
            else if (n[mid] < t) low = mid + 1;
            else high = mid-1;
        }
        return -1;
    }


    public int search(int[] nums, int target) {
        int n = nums.length;
        int pivot = findPivot(nums);

        int left = BS(nums, target, 0, pivot-1);
        if (left != -1) return left;

        return BS(nums, target, pivot, n-1);
    }
}