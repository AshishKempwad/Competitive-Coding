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
    vector<int>res;
    void inorder(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
        
    }
 
    int kthSmallest(TreeNode* root, int k)
    {
        
        inorder(root);
        
        for(int i=0;i<res.size();i++)
        {
            if(i == k-1)
            {
                return res[i];
            }
        }
        
        return -1;
    }
};
