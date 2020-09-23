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


