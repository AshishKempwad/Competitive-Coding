/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/
   
   
   
//TC = O(n)   

int find_dist(Node* root,int key,int level)
{
    if(!root)
    {
        return -1;
    }
    if(root->data == key)
    {
        return level;
    }
    
    int ans = find_dist(root->left,key,level+1);
    
    if(ans == -1)
    {
        return find_dist(root->right,key,level+1);
    }
    
    return ans;
    
}
   
Node* findlca(Node* root,int a,int b)
{
    if(!root) return NULL;
    
    if(root->data == a || root->data == b)
    {
        return root;
    }
    
    Node* left = findlca(root->left,a,b);
    Node* right = findlca(root->right,a,b);
    
    if(left && right)
    {
        return root;
    }
    else if(!left && right)
    {
        return right;
    }
    return left;
    
}
   
int findDist(Node* root, int a, int b)   //we will solve it by the knowledgr of lca
{
    Node* LCA = findlca(root,a,b);
    
    int d1 = find_dist(LCA,a,0); //(lca,node1,level zero)
    int d2 = find_dist(LCA,b,0);
    
    return d1+d2;
    // Your code here
}
