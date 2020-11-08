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
   
    
    TreeNode* helper(int instart,int inend,int post_start,vector<int>& inorder, vector<int>& postorder)
    {
        if(instart > inend)
        {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[post_start]);
        int inorder_index=-1;
        for(int i=instart;i<=inend;i++)
        {
            if(inorder[i]==root->val)
            {
                inorder_index=i;
                break;
            }
        }
        
       
        root->left = helper(instart,inorder_index-1,post_start-1+inorder_index-inend,inorder,postorder);
        root->right = helper(inorder_index+1,inend,post_start-1,inorder,postorder);
        
        return root;
    
    }
    
    
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        return helper(0,inorder.size()-1,postorder.size()-1,inorder,postorder);    
    }
};
