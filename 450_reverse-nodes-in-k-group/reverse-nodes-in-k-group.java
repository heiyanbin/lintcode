/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/reverse-nodes-in-k-group
@Language: Java
@Datetime: 15-10-13 06:56
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
     * @param k an integer
     * @return a ListNode
     */
    public ListNode reverseKGroup(ListNode head, int k) {
	// Write your code here
	ListNode p = head;
	int i = 0;
	for (; i < k && p != null; ++i) p = p.next;
	if (i < k) return head;
	ListNode head2 = null;
	for (ListNode cur = head; cur != p;) {
		ListNode next = cur.next;
		cur.next = head2;
		head2 = cur;
		cur = next;
	}
	head.next = reverseKGroup(p, k);
	return head2;
}
}
