/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/palindrome-linked-list
@Language: Java
@Datetime: 15-10-29 06:46
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    /**
     * @param head a ListNode
     * @return a boolean
     */
    public boolean isPalindrome(ListNode head) {
    	if (head == null || head.next == null) return true;
    	ListNode p = head, q = head;
    	for (; q != null && q.next != null;) {
    		p = p.next;
    		q = q.next.next;
    	}
    	if (q != null) p = p.next;
    	ListNode head2 = reverse(p);
    	for (p = head2, q = head; p != null; p = p.next, q = q.next) {
    		if (p.val != q.val) return false;
    	}
    	return true;
    }
    private ListNode reverse(ListNode head) {
    	ListNode head2 = null;
    	for (ListNode p = head; p != null;) {
    		ListNode next = p.next;
    		p.next = head2;
    		head2 = p;
    		p = next;
    	}
    	return head2;
    }
}
