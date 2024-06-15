class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {

        int n = profits.size();
        vector<pair<int,int>>vectorOfPairs(n);
        
        for(int i=0;i<n;i++){
            vectorOfPairs[i] = {capital[i],profits[i]};
        }

        sort(vectorOfPairs.begin(), vectorOfPairs.end());  //sorting based on captial(first value)

        priority_queue<int>maxHeap;   //max heap
        int i=0;

        while(k--){

            while(i<n && vectorOfPairs[i].first <= w){
                maxHeap.push(vectorOfPairs[i].second);
                i++;
            }

            if(!maxHeap.empty()){
                w += maxHeap.top();
                maxHeap.pop();
            } 
            else{
                break;
            }

            
        }

        return w;

    }
};
