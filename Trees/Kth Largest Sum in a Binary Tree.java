/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public long kthLargestLevelSum(TreeNode root, int k) {
        
        Queue<TreeNode> q = new LinkedList<>();
        PriorityQueue<Long> minHeap = new PriorityQueue<>();

        q.add(root);

        while(!q.isEmpty()){
            int size = q.size();
            long levelSum = 0;

            for(int i=0;i<size;i++){
                TreeNode current = q.poll();
                levelSum += current.val;

                if(current.left != null){
                    q.add(current.left);
                }
                if(current.right != null){
                    q.add(current.right);
                }
            }

            minHeap.add(levelSum);
            if(minHeap.size() > k){
                minHeap.poll();
            }
        }

        if(minHeap.size() < k){
            return -1;
        }

        return minHeap.peek();
    }
}
