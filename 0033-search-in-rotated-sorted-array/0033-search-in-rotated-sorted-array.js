/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var Solution = {
    findPivot: function(nums) {
        let low = 0, high = nums.length - 1;
        while (low < high) {
            let mid = Math.floor(low + (high - low) / 2);
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    },

    binarySearch: function(nums, target, low, high) {
        while (low <= high) {
            let mid = Math.floor(low + (high - low) / 2);
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    },

    search: function(nums, target) {
        if (nums.length === 0) return -1;
        const pivot = this.findPivot(nums);

        let left = this.binarySearch(nums, target, 0, pivot - 1);
        if (left !== -1) return left;

        return this.binarySearch(nums, target, pivot, nums.length-1);
    }
}
var search = function(nums, target) {
    return Solution.search(nums, target);
};