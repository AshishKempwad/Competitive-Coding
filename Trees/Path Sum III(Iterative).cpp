/*
You are given a binary tree in which each node contains an integer value.
Find the number of paths that sum to a given value.
The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11

*/

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
    
    void helper(TreeNode* root,int curr,unordered_map<int,int>&mp, int sum,int &ans)
    {
        if(!root)
        {
            return;
        }
        
        curr+=root->val;
        if(mp.find(curr-sum)!=mp.end())
        {
            ans+=mp[curr-sum];
        }
        
        mp[curr]++;
        helper(root->left,curr,mp,sum,ans);
        helper(root->right,curr,mp,sum,ans);
        mp[curr]--;
    }
    
    
    
    int pathSum(TreeNode* root, int sum)
    {
        
        unordered_map<int,int>mp;
        mp[0]++;
        int curr=0;
        int ans=0;
        helper(root,curr,mp,sum,ans);
        return ans;
        
    }
};
