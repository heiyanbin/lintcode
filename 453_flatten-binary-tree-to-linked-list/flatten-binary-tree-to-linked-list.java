/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/flatten-binary-tree-to-linked-list
@Language: Java
@Datetime: 15-10-29 08:04
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    public void flatten(TreeNode root) {
	    help(root);
    }
    private TreeNode help(TreeNode root) {
    	if (root == null) return null;
    	TreeNode leftLast = help(root.left);
    	TreeNode rightLast = help(root.right);
    	if (leftLast != null) {
    		leftLast.right = root.right;
    		root.right = root.left;
    		root.left = null;
    	} 
        if (rightLast != null) return rightLast;
        if (leftLast != null) return leftLast;
        return root;
    }
}
