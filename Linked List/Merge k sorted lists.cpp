///////using minheap
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
/////////////////////Using Divide and Conquer 
class Solution {
public:

   ListNode* merge(ListNode* left, ListNode* right){
       ListNode* dummy = new ListNode(-1);
       ListNode* head = dummy;

       while(left!=NULL && right!=NULL){
           if(left->val < right->val){
               head->next=left;
               left=left->next;
               head=head->next;
           }
           else{
               head->next=right;
               right=right->next;
               head=head->next;
           }
       }

       while(left!=NULL){
           head->next=left;
           left=left->next;
           head=head->next;
       }

       while(right!=NULL){
           head->next = right;
           right=right->next;
           head=head->next;
       }

       return dummy->next;
   }

   ListNode* mergeSort(vector<ListNode*>&lists, int start, int end){
       if(start==end){
           return lists[start];
       }
       int mid = start + (end-start)/2;
       ListNode* left = mergeSort(lists,start,mid);
       ListNode* right = mergeSort(lists,mid+1,end);
      return  merge(left,right);
   }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
       return mergeSort(lists,0,lists.size()-1);
    }
};
