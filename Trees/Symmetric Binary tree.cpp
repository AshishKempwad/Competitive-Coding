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
-----------------------------------------------------------------------------------------
    //Recursive, using the idea of SameTree
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
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(!p && !q){
            return true;
        }
        if(!p || !q){
            return false;
        }
        if(p->val == q->val && isSameTree(p->left,q->right) && isSameTree(p->right,q->left)){
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        if(isSameTree(root->left, root->right)){
            return true;
        }
        return false;
    }
};
