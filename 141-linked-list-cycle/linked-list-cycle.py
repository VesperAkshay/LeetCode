# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        l1 = head
        l2 = head

        while l1 and l1.next:
            l2 = l2.next
            l1 = l1.next.next
            if l1 == l2:
                return True
        return False
        