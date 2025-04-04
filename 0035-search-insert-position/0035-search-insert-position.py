class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums) - 1
        
        while low <= high:
            mid = low + (high - low) // 2
            # > Condition
            if target > nums[mid]:
                low = mid + 1
            # < Condition
            elif target < nums[mid]:
                high = mid - 1
            # == Condition
            else:
                return mid
        
        return low
