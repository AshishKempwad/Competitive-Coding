class Solution {
public:

  //TC = O(nlogn)
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int,priority_queue<int>>mp;

        for(auto item : items){
            mp[item[0]].push(item[1]);
        }
        vector<vector<int>>res;
        
        for(auto eachRowInMap : mp){
            int sum = 0;

            for(int i=0;i<5;i++){
                sum += eachRowInMap.second.top();
                eachRowInMap.second.pop();
            }

            res.push_back({eachRowInMap.first,sum/5});
        }

        return res;
    }
};
