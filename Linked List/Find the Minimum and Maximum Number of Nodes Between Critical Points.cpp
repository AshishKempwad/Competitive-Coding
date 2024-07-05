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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* p = head;
        ListNode* q = head->next;
        vector<int>criticalPoints;
        int position = 0;
        
        while(q->next != NULL){
            if((q->val < p->val && q->val < q->next->val) ||
               (q->val > p->val && q->val > q->next->val) ){
                    criticalPoints.push_back(position);
            }
            position++;
            p=p->next;
            q=q->next;
        }

        if(criticalPoints.size() < 2){
            return {-1,-1};
        }
        
        int maxD = criticalPoints.back() - criticalPoints.front();

        int minD = INT_MAX;

        for(int i=1;i<criticalPoints.size();i++){
            minD = min(minD, criticalPoints[i] - criticalPoints[i-1]);
        }

        return {minD,maxD};
    }
};
