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
    
    int res = 0;
    
    struct Info
    {
        int sum;
        int max;
        int min;
        int ans;
        bool isBST;
    };
    
    Info findBST(TreeNode* root)
    {
        if(!root)   //empty tree is a BST
        {
            return {0,INT_MIN,INT_MAX,0,true};
        }
        
        //Base condition for leaf nodes
        if(root->left==NULL && root->right==NULL)
        {
            return {root->val,root->val,root->val,root->val,true};
        }
        
        
        //Recursive equations
        
        Info l = findBST(root->left);
        Info r = findBST(root->right);
        
        Info temp;
        temp.sum =(root->val + l.sum + r.sum);
        
        if(l.isBST && r.isBST && l.max < root->val && r.min > root->val) // if the subtree rooted at the root is BST
        {
            temp.min = min(l.min,root->val);
            temp.max = max(r.max,root->val);
            
            temp.ans = temp.sum;
            temp.isBST = true;
            
            res = max(res,temp.ans);
            return temp;
        }
        //if  the whole tree is not BST
        
        temp.ans = max(l.ans,r.ans);
        
        res = max(temp.ans,res);
        temp.isBST = false;
        
        return temp;
        
    }
    
    int maxSumBST(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        
        return max(res,findBST(root).ans);
    }
};
