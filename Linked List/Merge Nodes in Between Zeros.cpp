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
    ListNode* mergeNodes(ListNode* head) {

        /*Approach 1 TC = O(n) SC = O(n+n)
          1. Have a result vector in which we will store the sum between 2 zeros.
          2. Calculate the sum between 2 zeros and store in the res vector.
          3. Now iterate over the res vector and create new Linked List and return
         */
        // vector<int>res;
        // int sum = 0;

        // while(head != NULL){
        //     if(head->val != 0){
        //         sum += head->val;
        //     }else{
        //         if(sum != 0){
        //            res.push_back(sum);
        //         }
        //         sum = 0;
        //     }
        //     head=head->next;
        // }

        // int n = res.size();

        // ListNode* root = new ListNode(-1);
        // ListNode* marker = root;
        // for(int i=0;i<n;i++){
        //     marker->next = new ListNode(res[i]);
        //     marker = marker->next;
        // }

        // return root->next;

        /*Approach 2 TC = O(n) SC = O(1)
           1. Take 2 pointers p1 and p2.
           2. Calculate the sum between 2 zeros
           3. Once you hit the next zero, update sum's val to p1 and point p1->next = p2->next 
               and make sum = 0 
        */

        ListNode* p1 = head->next;
        ListNode* p2 = head->next;
        ListNode* marker = p1;
        int sum = 0;

        while(p2 != NULL){
           if(p2->val != 0){
              sum += p2->val;
           }else{
            p1->val = sum;
            p1->next = p2->next;
            p1=p1->next;
            sum=0;
           }
           p2=p2->next;
        }

        return marker;



    }
};
