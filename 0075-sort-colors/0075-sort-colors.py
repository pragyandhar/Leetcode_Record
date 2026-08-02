class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        low, current, high = 0, 0, len(nums)-1

        while current <= high:
            if nums[current] == 0:
                nums[low], nums[current] = nums[current], nums[low]
                current += 1
                low += 1
            
            elif nums[current] == 2:
                nums[high], nums[current] = nums[current], nums[high]
                high -= 1
            
            else:
                current += 1