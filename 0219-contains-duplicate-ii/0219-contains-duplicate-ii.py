class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        s = set()

        i, j = 0, 0

        while j < len(nums):
            if abs(i-j) > k:
                s.remove(nums[i])
                i += 1
            
            if nums[j] in s:
                return True
            
            s.add(nums[j])
            j += 1
        
        return False