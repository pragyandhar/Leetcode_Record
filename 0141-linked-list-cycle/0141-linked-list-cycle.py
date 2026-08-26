# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, h: Optional[ListNode]) -> bool:
        if h is None:
            return False
        
        s, f = h, h.next

        while s and f:
            if not f or not f.next:
                return False
            
            if s == f:
                return True

            s = s.next
            f = f.next.next
        
        return False