/*Write a program to find the node at which the intersection of two singly linked lists begins.

Example 1:

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3

Output: Reference of the node with value = 8

Input Explanation:
The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). 
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. 
There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if(!headA || !headB)
        {
            return NULL;
        }
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        int cnt1=0;
        int cnt2=0;
        
        while(curr1!=NULL)
        {
            cnt1++;
            curr1=curr1->next;
            
        }
        while(curr2!=NULL)
        {
            cnt2++;
            curr2=curr2->next;
        }
        
        int diff = 0;
        
        curr1=headA;
        curr2=headB;
        
        if(cnt1 >= cnt2)
        {
           diff = cnt1-cnt2;
            
            for(int i=0;i<diff;i++)
            {
                curr1=curr1->next;
            }
        }
        else if(cnt1 < cnt2)
        {
            diff = cnt2-cnt1;
            for(int i=0;i<diff;i++)
            {
                curr2=curr2->next;
            }
        }
        
        while(curr1 && curr2)
        {
            if(curr1==curr2)
            {
                return curr1;
            }
            curr1=curr1->next;
            curr2=curr2->next;
        }
        
        return NULL;
    }
};
