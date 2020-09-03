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
    int minDepth(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        queue<TreeNode*>q;
        int res=0;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            res++;
            for(int i=0;i<n;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }    
                if(temp->left == NULL && temp->right==NULL)
                {
                    return res;
                }
            }
        }
        
        return -1;
    }
};
