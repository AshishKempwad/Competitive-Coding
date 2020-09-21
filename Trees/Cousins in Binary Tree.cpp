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
    bool isCousins(TreeNode* root, int x, int y)
    {
        if(root->val == x || root->val == y)
        {
            return false;
        }
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            bool foundx = false;
            bool foundy = false;
            for(int i=0;i<n;i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->val == x)
                {
                    foundx = true;
                }
                if(curr->val == y)
                {
                    foundy = true;
                }
                if(curr->right && curr->left)
                {
                    if((curr->left->val == x && curr->right->val == y) || (curr->left->val == y && curr->right->val == x))
                    {
                        return false;
                    }
                }
                
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            
            if(foundx && foundy)
            {
                return true;
            }
        }
        
        return false;
        
    }
};
