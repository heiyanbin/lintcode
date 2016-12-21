/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/merge-k-sorted-lists
@Language: Java
@Datetime: 14-12-29 06:01
*/

/**
 * Definition for ListNode.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) {
 *         this.val = val;
 *         this.next = null;
 *     }
 * }
 */ 
public class Solution {
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    public ListNode mergeKLists(List<ListNode> lists) {  
        PriorityQueue<ListNode> pq = new PriorityQueue<ListNode>(10, 
        		new Comparator<ListNode>() {
        			public int compare(ListNode a, ListNode b) {
        				if (a == null) return -1;
        				if (b == null) return 1;
        				return a.val - b.val;
        			}
        		});
        for ( ListNode e : lists) {
        	if (e != null) pq.offer(e);
        }
        ListNode dummy = new ListNode(-1);
        for (ListNode prev = dummy; !pq.isEmpty(); ) {
        	prev.next = pq.poll();
        	prev = prev.next;
        	if (prev.next != null) pq.offer(prev.next);
        }
        return dummy.next;
    }
}

