/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSymmetric(TreeNode* A) 
{
    if(!A)
    {
        return 1;
    }
    queue<TreeNode*>q;
    q.push(A);
    
    while(!q.empty())
    {
        int n = q.size();
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp->left)
            {
                q.push(temp->left);
                res.push_back(temp->left->val);
            }
            else
            {
                res.push_back(-1010);
            }
            if(temp->right)
            {
                q.push(temp->right);
                res.push_back(temp->right->val);
            }
            else
            {
                res.push_back(-1010);
            }
        }
        //  res.resize(q.size());
        int m = res.size();
        res.resize(m);
        int l=0;
        int r=m-1;
        
        while( r >= l)
        {
            if(res[l]!=res[r])
            {
                return 0;
            }
            
            r--;
            l++;
        }
      
    }
    
    return 1;
}
