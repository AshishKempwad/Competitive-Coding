/*
Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
ListNode* reverse(ListNode* head)
{
    ListNode* pre = NULL;
    ListNode* curr = head;
    
    while(curr!=NULL)
    {
        ListNode* nex = curr->next;
        curr->next=pre;
        pre=curr;
        curr=nex;
    }
    
    return pre;  //returns the head of the reversed list
}


ListNode* mergetwolists(ListNode* l1, ListNode* l2)
{
    ListNode* dummy = new ListNode(-1);
    ListNode* head = dummy;
    
    while(l1 && l2)
    {
        head->next=l1;
        head=l1;
        l1=l1->next;
        
        head->next=l2;
        head=l2;
        l2=l2->next;
    }
    
    if(!l1)
    {
        head->next=l2;
    }
    else
    {
        head->next=l1;
    }
    
    return dummy->next;
}

ListNode* Solution::reorderList(ListNode* head)
{
    
    // This question requires the idea of:
    //1)Finding the middle of linked list and splitting it into two halves
    //2)Reverse the second half of the linked list
    //3)Merge both the linkedlist one by one
    
    /*
    Explanation :
    
      Input : 1->2->3->4->5->6
      
      1) We find middle and split, so the two lists are:
          l1 = 1->2->3
        & l2 = 4->5->6 
      
      2) l2 = Reverse(l2), we get
         l2 = 6->5->4
         
      3) Merge l1 & l2 one by one.
      
        1->6->2->5->3->4
    */
    
    
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    
    ListNode* l1 = head;  //start of first list
    
    ListNode* slow = head;  // slow would be start of second list
    ListNode* fast = head;  //end of second list
    ListNode* prev = NULL;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        prev = slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    prev->next=NULL;   //prev is the end of the first list
    
    ListNode* l2 = reverse(slow);
    
    return mergetwolists(l1,l2);
    
}
