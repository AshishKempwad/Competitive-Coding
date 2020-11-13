#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char key;
    vector<Node *> child;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    return temp;
} 

int maxh(Node* root)
{
    if(!root)
    {
        return 0;
    }
    int maxdep=0;
    
    for(auto x: root->child)
    {
        maxdep = max(maxdep,maxh(x));
    }
    
    return maxdep+1;
}

int diameter(Node* root)
{
    if(!root)
    {
        return 0;
    }
    
    int max1=0;
    int max2=0;
    
    for(auto x : root->child)       //one node
    {
        int h = maxh(x);
        if(h > max1)
        {
            max2=max1;
            max1=h;
        }
        else
        {
            max2=h;
        }
    }
    
    int maxD=0;
    
    for(auto y : root->child)
    {
        maxD = max(maxD,diameter(y));
    }
    
    
    return max(maxD,max1+max2+1);
    
}


int main()
{
    /*   Let us create below tree
    *           A
    *         / /  \  \
    *       B  F   D  E
    *      / \     |  /|\
    *     K  J    G  C H I
    *      /\            \
    *    N   M            L
    */
 
    Node *root = newNode('A');
    (root->child).push_back(newNode('B'));
    (root->child).push_back(newNode('F'));
    (root->child).push_back(newNode('D'));
    (root->child).push_back(newNode('E'));
    (root->child[0]->child).push_back(newNode('K'));
    (root->child[0]->child).push_back(newNode('J'));
    (root->child[2]->child).push_back(newNode('G'));
    (root->child[3]->child).push_back(newNode('C'));
    (root->child[3]->child).push_back(newNode('H'));
    (root->child[3]->child).push_back(newNode('I'));
    (root->child[0]->child[0]->child).push_back(newNode('N'));
    (root->child[0]->child[0]->child).push_back(newNode('M'));
    (root->child[3]->child[2]->child).push_back(newNode('L'));
 
    cout << diameter(root) << endl;
 
    return 0;
}
