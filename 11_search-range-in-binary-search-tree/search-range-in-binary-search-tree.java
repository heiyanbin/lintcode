/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/search-range-in-binary-search-tree
@Language: Java
@Datetime: 14-12-25 07:35
*/

/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */
public class Solution {
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    public ArrayList<Integer> searchRange(TreeNode root, int k1, int k2) {
        // write your code here
        ArrayList<Integer> res = new ArrayList<Integer>();
        inOrder(root, k1, k2, res);
        return res;
    }
    void inOrder(TreeNode root, int k1, int k2, ArrayList<Integer> res) {
        if (root == null) return;
        if (k1 < root.val) inOrder(root.left, k1, k2, res);
        if (k1 <= root.val && root.val <= k2)  res.add(root.val);
        if (root.val < k2) inOrder(root.right, k1, k2, res);
    }
}
