class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = list()

        # Base Case
        if len(nums) == 1:
            return [nums[:]]
        
        for i in range(len(nums)):
            n = nums.pop(0)
            perm = self.permute(nums)

            for p in perm:
                p.append(n)
            result.extend(perm)
            nums.append(n)
        
        return result