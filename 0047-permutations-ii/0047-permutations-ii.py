class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        result = list()
        perms = list()
        # Count HashMap
        count = { n : 0 for n in nums }
        for n in nums:
            count[n] += 1
        
        def dfs():
            # Base Case
            if len(perms) == len(nums):
                result.append(perms[:])
            
            for n in count:
                if count[n] > 0:
                    perms.append(n)
                    count[n] -= 1
                    dfs() # Continue building the permutations
                    count[n] += 1
                    perms.pop()
        
        dfs()
        return result