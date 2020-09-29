/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) 
{
    
    priority_queue<int,vector<int>,greater<int>>minheap;
    
    for(auto x: A)
    {
        while(x!=NULL)
        {
            minheap.push(x->val);
            x=x->next;
        }
    }
    
    ListNode* temp = new ListNode(0);
    ListNode* head = temp;
    
    while(!minheap.empty())
    {
        temp->next = new ListNode(minheap.top());
        minheap.pop();
        temp = temp->next;
    }
    
    return head->next;
    
}
