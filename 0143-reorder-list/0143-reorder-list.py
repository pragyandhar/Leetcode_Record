# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        # Find the Mid Element
        slow = head
        fast = head

        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        
        # Break the link of the mid element
        curr = slow.next
        slow.next = None

        # Reverse the second list
        prev = None
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        
        # Combine the lists
        h1 = head
        h2 = prev

        while h2:
            temp = h1.next
            h1.next = h2
            h1 = h2
            h2 = temp
        
        