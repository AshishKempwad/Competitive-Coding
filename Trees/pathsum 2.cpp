/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void findpaths(TreeNode* root,int sum,vector<int>&path,vector<vector<int>>&paths)
{
    if(root==NULL)
    {
        return;
    }
    path.push_back(root->val);
    if(root->left == NULL && root->right == NULL && root->val == sum)
    {
        paths.push_back(path);
    }
    findpaths(root->left,sum-root->val,path,paths);
    findpaths(root->right,sum-root->val,path,paths);
    path.pop_back();
} 
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) 
{
    vector<vector<int>>paths;
    vector<int>path;
    findpaths(A,B,path,paths);
    return paths;
}
