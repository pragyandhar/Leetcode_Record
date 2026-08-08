class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)

        # Edge Case
        if k == 0:
            return nums

        result = [-1 for _ in range(n)]
        if n < 2*k+1:
            return result

        # Initialise the pointers
        left, right = 0, 2*k
        
        # Calculate the sum of the entire window
        window = 0
        for i in range(left, right+1):
            window += nums[i]
        
        # Calculate the average of the 
        avg = 0
        count = 2*k+1
        avg = (window) // (count)

        # Update the result
        j = k
        result[j] = avg
        j += 1

        # Incrasing right pointer on nums
        right += 1

        # Sliding the window
        while right < n:
            new_element_using_right = nums[right]
            old_element_using_left = nums[left]

            window = (window + new_element_using_right - old_element_using_left)
            avg = (window) // (count)

            result[j] = avg
            j += 1

            left += 1
            right += 1
        
        return result

            
