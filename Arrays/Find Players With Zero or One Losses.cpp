class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    /*The idea is simple. Just keep a track of loss. 
    If never lost then put in first vector and if lost exactly once then pt in 2nd vector.
    If won, then dont do anything, just pass that number in map.
    If lost, then increament that number in map.*/
       map<int,int>mp;

       for(auto &eachMatch : matches){
           mp[eachMatch[0]];
           mp[eachMatch[1]]++;
       }

       vector<int> neverLost;
       vector<int> lostOnce;

       for(auto [k,l] : mp){
           if(l == 0){
               neverLost.push_back(k);
           }
           if(l == 1){
               lostOnce.push_back(k);
           }
       }

       return {neverLost, lostOnce};
    }
};
