/*Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
*/

//Better Approach :

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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
      ListNode* curr = head;
        int count=1;
        while(curr!=NULL)
        {
            count++;
            curr=curr->next;
        }
        
        int pos = count-n-1;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp=dummy;
        temp->next=head;
        while(pos--)
        {  
            temp=temp->next;
        }
        temp->next = temp->next->next;
        return dummy->next;
    }
};

----------------------------------------------------------------------------------------------------------
//Best Method : In 1 pass

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
      //In one pass by using slow and fast pointer
        
        if(!head)
        {
            return head;
        }
        
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        for(int i=0;i<n;i++)
        {
            fast=fast->next;
        }
        
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        slow->next = slow->next->next;
        
        return dummy->next;
    }
};
