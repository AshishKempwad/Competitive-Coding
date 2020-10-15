/* Structure for tree and linked list*/

/* The DLL must be in the inorder traversal of tree*/

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
 Node* head = NULL;
 Node* prevDLL = NULL;

Node* DLL(Node* root)
{
    if(!root)
    {
        return NULL;
    }
    
    DLL(root->left);
    
    if(head == NULL)
    {
        head = root;
    }
    else
    {
        prevDLL->right = root;
        root->left = prevDLL;
    }
    
    prevDLL = root;
    DLL(root->right);
}


Node * bToDLL(Node *root)
{
    head = NULL;
    prevDLL = NULL;
    
    DLL(root);
    return head;
    
    
    // your code here
}
