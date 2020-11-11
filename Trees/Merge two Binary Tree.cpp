/*Given two Binary Trees A and B, you need to merge them in a single binary tree.
The merge rule is that if two nodes overlap, then sum of node values is the new value of the merged node.
Otherwise, the non-null node will be used as the node of new tree.
Problem Constraints
1 <= Number of Nodes in A , B <= 105

Input Format
First argument is an pointer to the root of binary tree A.
Second argument is an pointer to the root of binary tree B.

Output Format
Return a pointer to the root of new binary tree.

Input 1:

 A =   2

      / \

     1   4

    /

   5


B =   3
      / \
      6  1
      \   \
       2   7
       
 
Output 1:

     5
    / \
   7   5
  / \   \ 
 5   2   7 

*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* merge(TreeNode* A, TreeNode* B)
 {
     if(!A && !B)
     {
         return NULL;
     }
     else if(A && !B)
     {
         return A;
     }
     else if(!A && B)
     {
         return B;
     }
     else
     {
         A->val = A->val+B->val;
         A->left = merge(A->left,B->left);
         A->right = merge(A->right,B->right);
     }
     
     return A;
     
 }
 
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) 
{
    
    return merge(A,B);
}
