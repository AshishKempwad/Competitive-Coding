/*

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

*/

//Method 1: TC= 0(n) & SC=0(n)

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
    bool isPalindrome(ListNode* head)
    {
       vector<int>l1;
        while(head!=NULL)
        {
            l1.push_back(head->val);
            head=head->next;
        }
        
        vector<int>l2;
        l2=l1;
        reverse(l2.begin(),l2.end());
        
       if(l1==l2)
       {
           return true;
       }
        
        return false;
    }
};


------------------------------------------------------------------------------------------------------

//Method 2: TC=0(n) && SC=0(1)

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
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nex = NULL;
        
        while(curr!=NULL)
        {
            nex = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        
        return prev;
    }
    
    
    bool isPalindrome(ListNode* head) 
    {
        //Idea : Reverse the linked list from middle and then check if its same
        //from given head to middle and from start of reversed linkedlist to middle
        //Say, given is
        //1->2->3->3->2->1
        // 1->2->3<-3<-2<-1
        // h->           <-h1
        
        
        int len=0;
        ListNode* curr = head;
        while(curr)  //length of linkedlist
        {
            len++;
            curr=curr->next;
        }
        
        curr=head;
        for(int i=0;i<len/2;i++)
        {
            curr=curr->next;
        }
        
        ListNode* head2 = reverse(curr);
        
        while(head && head2)
        {
            if(head->val!=head2->val)
            {
                return false;    //not a palindrome
            }
            
            head=head->next;
            head2=head2->next;
        }
        
        return true;  //its a palindome
        
    }
};

