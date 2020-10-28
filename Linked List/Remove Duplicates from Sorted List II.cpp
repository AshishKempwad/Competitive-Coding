/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
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
    ListNode* deleteDuplicates(ListNode* head)
    {
       ListNode* dummy = new ListNode(-1);
       ListNode* curr = dummy;
       
        while(head)
        {
            int count=1;
            while(head->next && head->val==head->next->val)
            {
                count++;
                head=head->next;
            }
            if(count==1)
            {
                curr->next=head;
                curr=head;
            }
            head=head->next;
            curr->next=NULL;
        }
        return dummy->next;
        
    }
};
