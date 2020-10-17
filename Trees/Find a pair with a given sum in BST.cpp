class Solution {
public:
    
    bool dfs(TreeNode* root,int k,unordered_set<int>&set)
    {
        if(!root)
        {
            return 0;
        }
        if(set.count(k - root->val)==1)
        {
            return true;
        }
        set.insert(root->val);
        
        return dfs(root->left,k,set) || dfs(root->right,k,set);
    }
    
    
    
    bool findTarget(TreeNode* root, int k)
    {
        if(!root)
        {
            return 0;
        }
        unordered_set<int>set;
        return dfs(root,k,set);
        
    }
};
