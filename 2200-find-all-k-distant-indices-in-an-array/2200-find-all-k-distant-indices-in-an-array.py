class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        is_valid = [False] * len(nums)
        
        last_index = float('-inf')
        # Forward Pass
        for i in range(0, len(nums)):
            if nums[i] == key:
                last_index = i
            
            if abs(i - last_index) <= k:
                is_valid[i] = [True]

        last_index = float('-inf')
        # Backward Pass
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] == key:
                last_index = i
            
            if abs(i - last_index) <= k:
                is_valid[i] = [True]
        
        return [i for i in range(len(nums)) if is_valid[i]]