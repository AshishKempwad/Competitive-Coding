/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
Could you solve the problem in O(1) extra memory space?
You may not alter the values in the list's nodes, only nodes itself may be changed.
 

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
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
    int k_len(ListNode* head,int k)
    {
        while(head!=NULL && k>0)
        {
            head=head->next;
            k--;
        }
        if(k==0)
        {
            return 1;
        }
        return 0;
    }
    
    ListNode* reverseUtil(ListNode* head,int k)
    {
        int check = k_len(head,k);
        if(check==1)
        {
            ListNode* curr=head;
            ListNode* prev = NULL;
            ListNode* nex = NULL;
            int count=0;
            while(curr!=NULL && count<k)
            {
                nex = curr->next;
                curr->next=prev;
                prev=curr;
                curr=nex;
                count++;
            }
            if(nex!=NULL)
            {
                head->next = reverseUtil(nex,k);
            }
            
            return prev;
        }
        
        return head;
    }
    
    
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head || !head->next)
        {
            return head;
        }
       ListNode* res = reverseUtil(head,k);
        return res;
    }
};
