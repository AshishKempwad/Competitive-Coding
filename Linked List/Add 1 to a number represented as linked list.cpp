/*
A number N is represented in Linked List such that each digit corresponds to a node in linked list.
You need to add 1 to it.
For example 1999 is represented as (1-> 9-> 9 -> 9) and adding 1 to it should change it to (2->0->0->0)
Example 1:
Input:
LinkedList: 4->5->6
Output: 4->5->7 
*/

Node* reverse(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* nex = NULL;
    
    while(curr!=NULL)
    {
        nex = curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
    }
    return prev;
}


Node* addUtil(Node* head)
{
    Node* curr=head;
    int carry=1;   //we want to add 1
    int sum=0;
    Node* prev=NULL;
    Node* temp=NULL;
    
    while(curr!=NULL)
    {
        sum = carry+curr->data;
        carry=sum/10;
        sum = sum%10;
        curr->data=sum;
        temp=curr;
        curr=curr->next;
    }
    
    if(carry>=1)
    {
        Node* new_node = new Node(carry);
        temp->next = new_node;
    }
    
    return head;
}


Node* addOne(Node *head) 
{
    /*
    Below are the steps :
    1)Reverse given linked list. 
       For example, 1-> 9-> 9 -> 9 is converted to 9-> 9 -> 9 ->1.
    2)Start traversing linked list from leftmost node and add 1 to it.
      If there is a carry, move to the next node. 
      Keep moving to the next node while there is a carry.
    3)Reverse modified linked list and return head.
    */
    
    head=reverse(head);
    head=addUtil(head);
    head=reverse(head);
    return head;
}
