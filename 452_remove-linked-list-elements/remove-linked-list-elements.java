/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/remove-linked-list-elements
@Language: Java
@Datetime: 15-10-29 08:15
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
     * @param val an integer
     * @return a ListNode
     */
    public ListNode removeElements(ListNode head, int val) {
    	if (head == null) return head;
    	if (head.val == val) return removeElements(head.next, val);
    	head.next = removeElements(head.next, val);
    	return head;
    }
}
