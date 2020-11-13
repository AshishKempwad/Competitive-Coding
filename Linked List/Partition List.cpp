/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B)
{
    ListNode* first = new ListNode(-1);
    ListNode* second = new ListNode(-2);
    
    ListNode* f = first;
    ListNode* s = second;
    
    // ListNode* temp1 = A;
    while(A!=NULL)
    {
        if(A->val < B)
        {
            f->next = A;
            f=f->next;
        }
        else
        {
            s->next=A;
            s=s->next;
        }
        
        A=A->next;
    }
    
    s->next=NULL;
    f->next = second->next;
    
    return first->next;
}
