class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<int,vector<int>,greater<int>> minheap;  //syntax of minheap
        
        for(auto i : lists)
        {
            while(i!=NULL)
            {
                minheap.push(i->val);
                  i=i->next;
            }
        }
        
        ListNode *dummy = new ListNode(-1);
        ListNode * head = dummy;
        
        while(!minheap.empty())
        {
            ListNode *temp = new ListNode(minheap.top());
            head->next = temp;
            minheap.pop();
            head=head->next;
        }
        
       return dummy->next;
        
    }
};
