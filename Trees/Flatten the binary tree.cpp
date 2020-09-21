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
    void flatten_tree(TreeNode* root, TreeNode* &head)
    {
        if(root == NULL)
        {
            return;
        }
        flatten_tree(root->right,head);
        flatten_tree(root->left,head);
        root->left = NULL;
        root->right = head;
        head = root;
    }
    
    
    
    void flatten(TreeNode* root) 
    {
        TreeNode* head = NULL;
        flatten_tree(root,head);
        
    }
};
