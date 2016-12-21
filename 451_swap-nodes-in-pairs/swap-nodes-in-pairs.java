/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/swap-nodes-in-pairs
@Language: Java
@Datetime: 15-10-29 08:26
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
     * @return a ListNode
     */
    public ListNode swapPairs(ListNode head) {
    	if (head == null || head.next == null) return head;
    	ListNode second = head.next, third = head.next.next;
    	second.next = head;
    	head.next = third;
    	head.next = swapPairs(third);
    	return second;
    }
}
