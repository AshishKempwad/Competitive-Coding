/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* head)
{
    ListNode* prev = NULL;
    ListNode* curr = head;
    
    while(curr->next!=NULL)
    {
        ListNode* nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr=nex;
    }
    curr->next=prev;
    return curr;
}
