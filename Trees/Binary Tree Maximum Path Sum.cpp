/*Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any node sequence from some starting node to any
node in the tree along the parent-child connections.
The path must contain at least one node and does not need to go through the root.

Example 1:


Input: root = [1,2,3]
Output: 6

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

int maxsum;
class Solution {
public:
    
    int pathsum(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        
        int leftsum = max(0,pathsum(root->left));
        int rightsum = max(0,pathsum(root->right));
        
        maxsum = max(maxsum,leftsum+rightsum+root->val);     /// max sum rooted at that node
        return max(leftsum,rightsum)+root->val;   // return maxsum from one of the path
                          
    }
    
    int maxPathSum(TreeNode* root) 
    {
        maxsum=INT_MIN;
        pathsum(root);
        return maxsum;
    }
};
