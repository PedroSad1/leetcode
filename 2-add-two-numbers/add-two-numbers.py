# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        current1 = l1
        current2 = l2

        string1 = ''
        string2 = ''

        while current1:
            string1 = str(current1.val) + string1
            current1 = current1.next
            
        while current2:
            string2 = str(current2.val) + string2
            current2 = current2.next

        sum_value = str(int(string1) + int(string2))

        result = ListNode(int(sum_value[len(sum_value) - 1]))
        current_result = result

        for i in range(len(sum_value) - 2, -1, -1):
            current_result.next = ListNode(int(sum_value[i]))
            current_result = current_result.next

        return result
        