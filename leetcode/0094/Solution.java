/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 * 100.00%,5.79%
 */
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList();
        inorderTraversal(root, list);
        return list;
    }

    private void inorderTraversal(TreeNode root, List<Integer> list){
        if(root != null){
            inorderTraversal(root.left, list);
            list.add(root.val);
            inorderTraversal(root.right, list);
        }
    }
}
