/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 /*
 Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
 */
ListNode* Solution::rotateRight(ListNode* A, int B)
{
   if(A==NULL || A->next==NULL)
   {
       return A;
   }
   int cnt=0;
   ListNode* temp=A;
   while(temp->next!=NULL)
   {
       temp=temp->next;
       cnt++;
   }
   cnt++;
   
   temp->next = A;
   temp=A;
   B = B%cnt;
   
   int target = cnt - B;
   
   for(int i=0;i<target-1;i++)
   {
       temp=temp->next;
   }
   A = temp->next;
   temp->next=NULL;
   
   
   return A;
}



