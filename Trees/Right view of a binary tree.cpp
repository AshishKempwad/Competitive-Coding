/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A)
{
    if(!A)
    {
        return {};
    }
    queue<TreeNode*>q;
    vector<int>res;
    
    q.push(A);
    // res.push_back(A->val);
    
    while(!q.empty())
    {
        int n = q.size();
        res.push_back(q.back()->val);
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
        }
    }
    
    return res;
    
    

 
}
