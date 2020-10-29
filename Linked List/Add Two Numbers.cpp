/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
       ListNode* dummy = new ListNode(-1);
        ListNode* l3 = dummy;
        
        int carry=0;
        
        while(l1!=NULL || l2!=NULL)
        {
            int l1_val;
            int l2_val;
            
            
            if(l1)
            {
                l1_val = l1->val;
            }
            else
            {
                l1_val = 0;
            }
            
             if(l2)
            {
                l2_val = l2->val;
            }
            else
            {
                l2_val = 0;
            }
            
            int curr_sum = l1_val + l2_val + carry;
            carry = curr_sum/10;
            int last_digit = curr_sum%10;
            
            ListNode* new_node = new ListNode(last_digit);
            l3->next=new_node;
            
            if(l1)
            {
                l1=l1->next;
            }
            if(l2)
            {
                l2=l2->next;
            }
            
            l3=l3->next;
            
        }
        
          if(carry > 0)
            { 
              ListNode* new_node = new ListNode(carry);
                l3->next = new_node;
              l3=l3->next;
            }
        
        return dummy->next;
        
    }
};
