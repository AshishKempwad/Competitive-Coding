/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//Recursive way
TreeNode* Solution::invertTree(TreeNode* A)
{
    if(A==NULL)
    {
        return NULL;
    }
    invertTree(A->left);
    invertTree(A->right);
    swap(A->left,A->right);
    
    return A;
}


//Iterative way

void invert(TreeNode *root)
{
    if(!root)
        return;
    
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    invert(root->left);
    invert(root->right);
}
 
TreeNode* Solution::invertTree(TreeNode* A) 
{
    invert(A);
    return A;
}
