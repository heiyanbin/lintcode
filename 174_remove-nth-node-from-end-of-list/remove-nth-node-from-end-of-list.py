# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/remove-nth-node-from-end-of-list
@Language: Python
@Datetime: 15-01-15 01:15
'''

"""
Definition of ListNode
class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""
class Solution:
    """
    @param head: The first node of linked list.
    @param n: An integer.
    @return: The head of linked list.
    """
    def removeNthFromEnd(self, head, n):
        if n < 1: return head
        
        i, q = 0, head
        while q != None and i < n:
            i += 1
            q = q.next
        if i < n: return head
        
        dummy = ListNode(0)
        p, dummy.next = dummy, head
        while q != None:
            q = q.next
            p = p.next
        p.next = p.next.next
        
        return dummy.next