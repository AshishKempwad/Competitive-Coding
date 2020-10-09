/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
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

