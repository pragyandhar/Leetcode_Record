class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        # Find the j
        index = []

        for i in range(0, len(nums)):
            if nums[i] == key:
                index.append(i) 

        # OBJECTIVE ACHIEVED SO FAR: Now my index has all the indexes that are going to be used in |i-j|<=k

        result = []

        for i in range(0, len(nums)):
            ans = float('inf')
            for j in index:
                ans = min(abs(i-j), ans)
            if ans <= k:
                result.append(i)
        
        return result