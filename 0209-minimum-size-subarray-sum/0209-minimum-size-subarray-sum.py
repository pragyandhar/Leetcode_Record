class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        i, j = 0, 0
        SUM = 0

        ans = float('inf')

        while j < len(nums):
            SUM += nums[j]

            while SUM >= target :
                ans = min(ans, j - i + 1)

                SUM -= nums[i]
                i += 1
            
            j += 1
        
        return 0 if ans == float('inf') else ans