/*Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example 1:
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: l1 = [], l2 = []
Output: []

Example 3:
Input: l1 = [], l2 = [0]
Output: [0]
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
       if(!l1 && !l2)
       {
           return NULL;
       }
        if(!l1)
        {
            return l2;
        }
        if(!l2)
        {
            return l1;
        }
        
        ListNode* head = NULL;
        if(l1->val < l2->val)
        {
            head=l1;
            l1=l1->next;
        }
        else
        {
            head=l2;
            l2=l2->next;
        }
        
        ListNode* temp = head;
        
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                temp->next = l1;
                l1=l1->next;
            }
            else
            {
                temp->next=l2;
                l2=l2->next;
            }
            
            temp=temp->next;
        }
        
        if(l1)
        {
            temp->next=l1;
        }
        
        if(l2)
        {
            temp->next=l2;
        }
        
        return head;
    }
};
