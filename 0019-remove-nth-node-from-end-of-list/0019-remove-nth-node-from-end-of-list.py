# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, h: Optional[ListNode], n: int) -> Optional[ListNode]:
        length = 0
        curr = h

        while curr:
            length += 1
            curr = curr.next

        if n == length:
            return h.next

        i, j = h, h.next

        for _ in range(length-n-1):
            j = j.next
            i = i.next

        temp = j.next
        j.next = None
        i.next = temp

        return h