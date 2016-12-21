# coding:utf-8
'''
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/nth-to-last-node-in-list
@Language: Python
@Datetime: 15-01-15 01:02
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
    @return: Nth to last node of a singly linked list. 
    """
    def nthToLast(self, head, n):
        p, q, i = head, head, 0
        
        while q != None and i < n:
            i += 1
            q = q.next
        
        if i < n: return None
        
        while q != None:
            p = p.next
            q = q.next
            
        return p