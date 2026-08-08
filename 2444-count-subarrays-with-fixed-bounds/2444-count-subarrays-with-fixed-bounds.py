class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        ans = 0

        minKPos = maxKPos = culpritIdx = -1

        for i, num in enumerate(nums):
            if num < minK or num > maxK:
                culpritIdx = i
            
            if num == minK:
                minKPos = i
            
            if num == maxK:
                maxKPos = i
            
            # smaller = min(minKPos, maxKPos)
            # temp = smaller - culpritIdx
            # ans += 0 if temp <= 0 else temp

            ans += max(0, min(minKPos, maxKPos) - culpritIdx)

        return ans