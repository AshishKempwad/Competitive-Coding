/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) 
{
    
    if(!A)
    {
        // return {};
        return vector<vector<int>>();
    }
    vector<vector<int>>res;
    queue<TreeNode*>q;
    q.push(A);
    
    bool left_to_right = 1;   //Flag to decide the direction in zig-zag
    
    while(!q.empty())
    {
        int n = q.size();
        vector<int>v(n);
        
        for(int i=0;i<n;i++)
        {
            TreeNode* curr = q.front();
            q.pop();
            
            int index;
            if(left_to_right == 1)
            {
                index = i;
            }
            else
            {
                index = n-i-1;
            }
            v[index] = curr->val;
            
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
        }
        
        left_to_right = 1 - left_to_right;
        res.push_back(v);
        
    }
    
    return res;
    
}
