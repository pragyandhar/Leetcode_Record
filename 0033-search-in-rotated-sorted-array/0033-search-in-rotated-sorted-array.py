class Solution:
    def findPivot(self, nums: List[int]) -> int:
        low, high = 0, len(nums) - 1
        while low < high:
            mid = low + (high - low) // 2
            if nums[mid] > nums[high]:
                low = mid + 1
            else:
                high = mid
        return low
    
    def BinarySearch(self, nums: List[int], target: int, low: int, high: int) -> int:
        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                low = mid + 1
            else :
                high = mid - 1
        return -1
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1
        n = len(nums)
        pivot = self.findPivot(nums)
        left = self.BinarySearch(nums, target, 0, pivot-1)
        if left != -1:
            return left
        
        return self.BinarySearch(nums, target, pivot, n-1)
        