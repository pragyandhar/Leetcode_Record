class Solution:
    def findDuplicate(self, n: List[int]) -> int:
        # Initialise the slow and fast pointer
        slow = n[0]
        fast = n[n[0]]

        # Detect Cycle
        while slow != fast:
            slow = n[slow]
            fast = n[n[fast]]
        
        # Find the repeated number or enterance to the cycle
        slow = 0
        while slow != fast:
            slow = n[slow]
            fast = n[fast]
        
        return slow