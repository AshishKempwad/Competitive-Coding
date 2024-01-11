//Brute Force

class Solution {
public:

    int maxDiff = -1;

    void maxDiffUtil(TreeNode* root, TreeNode* child){
        if(!child){
            return;
        }
        /*Compute the maxDiff throughout*/
        maxDiff = max(maxDiff, abs(root->val - child->val));

        /*Root is fixed we go to left and right as its child and compute*/ 
        maxDiffUtil(root, child->left);
        maxDiffUtil(root, child->right);
    }

    void helper(TreeNode* root){
     
     /*Initailly we fix the root and pass root->left & root->right as its child*/
        maxDiffUtil(root, root->left);
        maxDiffUtil(root, root->right);

    /*We need to check that for every root of every subtree.
    If root->left and root->right are present, we pass them to self function so
     that all the children of root are also root of their subtree*/
        if(root->left){
            helper(root->left);
        }
        if(root->right){
            helper(root->right);
        }
    }

    int maxAncestorDiff(TreeNode* root) {
        /*The idea is simple by fixing each node as root, we calculate the maxDiff of its subtree.
        We then return the maxDiff*/
        
        helper(root);
        return maxDiff;
    }
};

//Optimal Solution:


class Solution {
public:
    int maxDiff = INT_MIN;
    int minDiff = INT_MAX;

    int helper(TreeNode* root, int maxDiff, int minDiff){
        /*When we reach end of path, compute the difference between maxValue node and minValue node found on the path*/
        if(!root){
            return abs(maxDiff - minDiff);
        }
        /*Need to compute/update min and max at every node of the path*/
        minDiff = min(minDiff, root->val);
        maxDiff = max(maxDiff, root->val);

        /*Call the same helper function on both left and right sides*/
        int l = helper(root->left, maxDiff, minDiff);  //MaxDiff from left
        int r = helper(root->right, maxDiff, minDiff); //MaxDiff from right

        /*return the maximum difference we have found. Maximum difference would be max of what we have found an dleft and found on right*/
        return max(l,r);
    }

    int maxAncestorDiff(TreeNode* root) {
        /*Here idea is simple, we compute max and min for every path and finally return the maxDiff between max and min*/
        return helper(root, maxDiff, minDiff);
    }
};
