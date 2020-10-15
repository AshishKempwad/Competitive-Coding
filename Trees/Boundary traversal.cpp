/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */


void printRight(Node* root,vector<int>&res)
{
    if(!root)
    {
        return;
    }
    if(root->right)
    {
        printRight(root->right,res);
        res.push_back(root->data);
    }
    else if(root->left)
    {
        printRight(root->left,res);
        res.push_back(root->data);
    }
}


void printleaf(Node* root,vector<int>&res)
{
    if(!root)
    {
        return;
    }
    printleaf(root->left,res);
    
    if(!root->left && !root->right)
    {
        res.push_back(root->data);
    }
    
    printleaf(root->right,res);
}

void printLeft(Node* root, vector<int>&res)
{
    if(!root)
    {
        return;
    }
    if(root->left)
    {
        res.push_back(root->data);
        printLeft(root->left,res);
    }
    else if(root->right)
    {
        res.push_back(root->data);
        printLeft(root->right,res);
    }
}

vector <int> printBoundary(Node *root)
{
    vector<int>res;
   if(!root) return {};
   
   res.push_back(root->data);
    printLeft(root->left,res);//Top down left boundary
    printleaf(root->left,res);  //Leaf nodes at left
    printleaf(root->right,res); //Leaf nodes at right
    printRight(root->right,res);  //Bottum up manner
    
    return res;
    
     //Your code here
}
