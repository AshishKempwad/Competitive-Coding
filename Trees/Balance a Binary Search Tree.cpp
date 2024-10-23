/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void inorder(TreeNode* root, vector<int>&inorderTraversal){
        if(!root){
            return;
        }
        inorder(root->left,inorderTraversal);
        inorderTraversal.push_back(root->val);
        inorder(root->right,inorderTraversal);
    }

    TreeNode* constructBalancedBST(vector<int>&inorderTraversal, int left, int right){

        if( left > right){
            return NULL;
        }

           int mid = left + (right - left)/2;
           TreeNode* root = new TreeNode(inorderTraversal[mid]);
           root->left = constructBalancedBST(inorderTraversal,left,mid-1);
           root->right = constructBalancedBST(inorderTraversal,mid+1,right);

           return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        /*Given Tree is already a BST.
          That means its inorder traversal would give us an sorted array.
          Just construct the balanaced binary search tree using from sorted array using arr[mid] as root.
        */

        if(!root){
            return NULL;
        }
        vector<int>inorderTraversal;
        inorder(root,inorderTraversal);
        int left = 0;
        int right = inorderTraversal.size()-1;

       return constructBalancedBST(inorderTraversal,left,right);
        
    }
};


#################################################JAVA########################################
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

    private void inorderTraversal(TreeNode root,List<Integer>inorder){
        if(root == null){
            return;
        }
        inorderTraversal(root.left,inorder);
        inorder.add(root.val);
        inorderTraversal(root.right,inorder);

    } 

    private TreeNode constructbalanceBST(List<Integer>inorder,int left, int right){
        if(left > right){
            return null;
        }

        int mid = left + (right - left)/2;

        TreeNode root = new TreeNode(inorder.get(mid));
        root.left = constructbalanceBST(inorder,left,mid-1);
        root.right = constructbalanceBST(inorder,mid+1,right);

        return root;

    }

    public TreeNode balanceBST(TreeNode root) {
        if(root == null){
            return root;
        }

        List<Integer> inorder = new ArrayList<>();
        inorderTraversal(root,inorder);
        return constructbalanceBST(inorder,0,inorder.size()-1);
    }
}
