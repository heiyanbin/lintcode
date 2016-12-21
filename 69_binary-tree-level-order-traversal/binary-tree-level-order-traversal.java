/*
@Copyright:LintCode
@Author:   heiyanbin
@Problem:  http://www.lintcode.com/problem/binary-tree-level-order-traversal
@Language: Java
@Datetime: 14-12-27 00:50
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
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
    public ArrayList<ArrayList<Integer>> levelOrder(TreeNode root) {
        // write your code here
        ArrayList res = new ArrayList();
        if (root == null) return res;
        
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(root);
        
        while (!q.isEmpty()) {
            ArrayList<Integer> level = new ArrayList<Integer>();
            int levelSize = q.size();
            for (int i = 0; i < levelSize; ++i) {
                root = q.poll();
                level.add(root.val);
                if (root.left != null) q.offer(root.left);
                if (root.right != null) q.offer(root.right);
            }
            res.add(level);
        }
        
        return res;
    }
}
