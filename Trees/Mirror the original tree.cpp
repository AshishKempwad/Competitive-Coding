Node* mirror = NULL;

void mirrorify(Node* root, Node* mirror)
{
   if(root == NULL)
   {
      mirror = root;
      return;
   }
   
  *mirror = Node(root->val);   //create the copy of root
   mirrorify(root->left, mirror->right);   // we make left half of original tree as right in mirror tree and right as left and hence create the mirror.
   mirrorify(root->right,mirror->left);
   
}


void mirror_the_tree(Node* root)
{
   mirrorify(root,mirror);
}
