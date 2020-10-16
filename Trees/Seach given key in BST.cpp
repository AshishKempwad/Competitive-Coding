Node* search(Node* root , int target)
{
   if(!root)
   {
      return NULL;
   }
   if(root->val == target)
   {
      return root;
   }
   
   if(root->val > target)
   {
      return search(root->left,target);
   }
   
   return search(root->right,target);
   
}
