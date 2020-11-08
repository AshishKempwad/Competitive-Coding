/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* helper(int prestart,int instart,int inend,vector<int> &preorder, vector<int> &inorder)
{
    if(prestart > preorder.size()-1 || instart > inend)
    {
        return NULL;
    }
    
    TreeNode* root = new TreeNode(prestart);
    
    int inindex = 0;
    
    for(int i=instart;i<=inend;i++)
    {
        if(root->val == inorder[i])
        {
            inindex=i;                //found root in inorder
        }
    }
    
    root->left = helper(prestart+1,instart,inindex-1,preorder,inorder);
    root->right = helper(prestart + inindex-instart+1,inindex+1,inend,preorder,inorder);
    
    return root;
    
    
    
}
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return helper(0,0,inorder.size()-1,preorder,inorder);
}

-----------------------------------------------------------------------------------------------
 //easy implementation
 
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
    int prestart=0;
    TreeNode* helper(int instart,int inend, vector<int>& inorder,vector<int>& preorder)
    {
        if(instart > inend)
        {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[prestart]);
        int inorder_index=-1;
        for(int i=instart;i<=inend;i++)
        {
            if(inorder[i]==root->val)
            {
                inorder_index=i;
                break;
            }
        }
        
        prestart++;
        
        root->left = helper(instart,inorder_index-1,inorder,preorder);
        root->right = helper(inorder_index+1,inend,inorder,preorder);
        
        return root;
    }
    
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return helper(0,inorder.size()-1,inorder,preorder);
    }
};
