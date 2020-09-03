/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
// Recursive method

int Solution::maxDepth(TreeNode* A) 
{
    if(A==NULL)
    {
        return 0;
    }
    
    return max(maxDepth(A->left),maxDepth(A->right))+1;
}

//Iterative method

class Solution {
public:
    int maxDepth(TreeNode* root)
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
            int n=q.size();
          
            res++;
            for(int i=0;i<n;i++)
            {
                  TreeNode *t=q.front();
                   q.pop(); 
                
                
                if(t->left)
                {
                    q.push(t->left);
                }
                if(t->right)
                {
                    q.push(t->right);
                }
                
            }
        }
        return res;
    } 
};
