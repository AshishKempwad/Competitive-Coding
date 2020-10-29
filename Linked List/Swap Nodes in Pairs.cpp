/*
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes. Only nodes itself may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode* curr = dummy;
        
        while(curr->next!=NULL && curr->next->next!=NULL)
        {
            ListNode* first = curr->next;
            ListNode* second = curr->next->next;
            
            first->next=second->next;
            curr->next=second;
            curr->next->next=first;
            curr=curr->next->next;
        }
        
        return dummy->next;
        
    }
};
