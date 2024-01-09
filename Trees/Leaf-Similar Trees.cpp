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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leftSideLeafs;
        vector<int>rightSideLeafs;

        getLeafValues(root1,leftSideLeafs);
        getLeafValues(root2,rightSideLeafs);

        return leftSideLeafs == rightSideLeafs;
    }

    void getLeafValues(TreeNode* root, vector<int>&leafList){
        if(!root){
            return;
        }

        if(!root->left && !root->right){
            leafList.push_back(root->val);
            return;
        }

        getLeafValues(root->left, leafList);
        getLeafValues(root->right, leafList);
    }
};
