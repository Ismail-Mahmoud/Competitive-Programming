# https://leetcode.com/problems/linked-list-cycle-ii/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow, fast = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                break
        else:   # normal loop termination
            return None
        
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next
        return slow

"""
Distance traveled by both slow (S) and fast (F)

H       LoopStart   MeetingPoint
+_____a_____+______b______+
            |______c______|

S = a + b
F = a + b + c + b = a + 2b + c
F = 2S
a + 2b + c = 2a + 2b
c = a #
"""
