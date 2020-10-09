/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */


//Better Approach

//TC = O(n)
//SC = O(n)    

RandomListNode* Solution::copyRandomList(RandomListNode* head) 
{
    RandomListNode* curr = head;
    RandomListNode* clonecurr = NULL;
    unordered_map<RandomListNode*,RandomListNode*>mp;
    while(curr!=NULL)
    {
        clonecurr = new RandomListNode(curr->label);
        mp[curr] = clonecurr;
        curr=curr->next;
    }
    
    curr=head;
    
    while(curr!=NULL)
    {
        clonecurr = mp[curr];
        clonecurr->next = mp[curr->next];
        clonecurr->random = mp[curr->random];
        curr = curr->next;
    }
    curr = head;
    clonecurr = mp[curr];
    
    return clonecurr;
}

-----------------------------------------------------------------------------------------------
 
 //Most optimized Approach   
    
//TC = O(n)
//SC = O(1)    
    
    
RandomListNode* Solution::copyRandomList(RandomListNode* head) 
{
   RandomListNode* dummy=NULL;
   RandomListNode* curr = head;
   
   
   //Take care of next pointers
   while(curr!=NULL)
   {
       dummy = curr->next;
       curr->next = new RandomListNode(curr->label);
       curr->next->next = dummy;
       curr=dummy;
   }
   
   curr = head;
   //Take care of random pointers
   while(curr!=NULL)
   {
       if(curr->random!=NULL)
       {
           curr->next->random = curr->random->next;
       }
     
       curr = curr->next->next;
   }
   
   //segregate original and copy nodes
   
   curr = head;
   dummy = head->next;
   RandomListNode* temp = dummy;
  
   while(curr && dummy)
   {
     if(curr->next)
     {
         curr->next = curr->next->next;
     }
     
     if(dummy->next)
     {
         dummy->next = dummy->next->next;
     }
     
     dummy = dummy->next;
     curr = curr->next;
   }
   return temp;
   
   
   
  
}
