class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res;
       unordered_map<int,int>mp;
       int maxFreq = 0;

//Calculate and store the frequence in the map
       for(auto &x : nums){
           mp[x]++;
       }
//Calculate max frequency
       
       for(auto &y : mp){
           maxFreq = max(maxFreq,y.second);
       }

       for(int i=0;i<maxFreq;i++){
           vector<int>temp;

           for(auto &ele : mp){
               if(ele.second > 0){
                   temp.push_back(ele.first);
                   ele.second--;
               }
           }
           res.push_back(temp);
       }

       return res;
    }
};
