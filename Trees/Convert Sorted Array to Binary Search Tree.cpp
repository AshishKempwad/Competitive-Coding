/*

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.size()==0)
        {
            return NULL;
        }
        else if(nums.size()==1)
        {
            TreeNode* root = new TreeNode(nums[0]);
            return root;
        }
       
            int mid = nums.size()/2;
            
            TreeNode* root = new TreeNode(nums[mid]);
            
            vector<int>left_part(nums.begin(),nums.begin()+mid);
            vector<int>right_part(nums.begin()+mid+1,nums.end());
            
            root->left = sortedArrayToBST(left_part);
            root->right = sortedArrayToBST(right_part);
            
            return root;
        
    }
};
