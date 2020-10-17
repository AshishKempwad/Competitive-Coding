int find_floor(Node* root,int key)
{ 
    int floor = -1;
    
    while(root)
    {
        if(root->data == key)
        { 
           floor = root->data;
           retur floor;
        }
        
        if(root->data < key)
        {
            floor=root->data;
            root=root->right;
        }
        else
        {
          root=root->left;
        }
    }
    
    return floor;
}
