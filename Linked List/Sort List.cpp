/*
Given the head of a linked list, return the list after sorting it in ascending order.
Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

 
Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []
 
Constraints:
The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
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
    
    //Solved it using two methods:
    // 1) Middle of a linkedlist
    // 2) Merge two sorted lists
    
    
    ListNode* sortList(ListNode* head)
    {
       //We will use the idea of mergesort here
        
        if(head==NULL || head->next==NULL)   // if no element return null, else if one element return that as single element is always sorted.
        {
            return head;
        }
        
        ListNode* mid = middleNode(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return mergetwolists(left,right);
    }
    
    ListNode* middleNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* mid;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        mid = slow->next;  //right half being pointed by left . Here we divide the list in two halves
        slow->next=NULL;
        return mid;
    }
    
    ListNode* mergetwolists(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;
        
       while(l1 && l2)
       {
           if(l1->val <= l2->val)
           {
               current->next=l1;
               l1=l1->next;
           }
           else
           {
               current->next=l2;
               l2=l2->next;
           }
           
           current=current->next;
       }
        
        if(l1)
        {
            current->next=l1;
        }
        else
        {
            current->next=l2;
        }
        
        return dummy->next;
        
    }

};

