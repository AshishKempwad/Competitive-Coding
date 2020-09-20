/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* A) 
{
    unordered_map<TreeNode*,int>mp;
    vector<int>res;
    stack<TreeNode*>s;
    s.push(A);
    
    while(!s.empty())
    {
        TreeNode* curr = s.top();
        
        if(curr == NULL)
        {
            s.pop();
            continue;
        }
        
        if(mp[curr] == 0)
        {
            s.push(curr->left);
        }
        else if(mp[curr] == 1)
        {
            s.push(curr->right);
        }
        else if(mp[curr] == 2)
        {
            res.push_back(curr->val);
        }
        else
        {
            s.pop();
        }
        
        mp[curr]++;
    }
    
    return res;
}
