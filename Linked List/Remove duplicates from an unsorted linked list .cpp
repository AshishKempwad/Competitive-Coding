/*
Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List.
When a value appears in multiple nodes, the node which appeared first should be kept, all others duplicates are to be removed.
*/

Node * removeDuplicates( Node *head) 
{
    Node* curr = head;
    Node* prev = NULL;
    unordered_set<int>s;
 
    while(curr!=NULL)
    {
        if(s.find(curr->data)!=s.end())
        {
            curr=curr->next;
            prev->next=prev->next->next;
        }
        else
        {
            s.insert(curr->data);
            prev = curr;
            curr=curr->next;
        }
    }
    return head;
   
 
}
