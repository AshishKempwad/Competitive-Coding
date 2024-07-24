class Solution {
public:

    string getMapped(string &numsStr, vector<int>& mapping){

        string res = "";

        for(int i=0;i<numsStr.size();i++){

            char ch = numsStr[i];

            int idx = ch - '0';

            res += to_string(mapping[idx]);
        }

        return res;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        /* Approach 1 :
           1) Convert each number in nums to its coressponding number using mapping vector
           2) Convert all numbers to string as accessing the elements becomes easier
           3) Have a vector of pair<int,int> => pair<mappedNumber,indexOfOriginalNumberInGivenNums>
           4) Sort the vector
           5) Return the result using indexOfOriginalNumberInGivenNums from sorted vector
        */
        vector<pair<int,int>>vec;
        
        for(int i=0;i<nums.size();i++){
            string numsStr = to_string(nums[i]);

            string mappedString = getMapped(numsStr,mapping);

            int mappedNumber = stoi(mappedString);

            vec.push_back({mappedNumber,i});
        }

        sort(vec.begin(),vec.end());

        vector<int>res;

        for(auto &x : vec){
            int originalIndex = x.second;
            res.push_back(nums[originalIndex]);
        }

        return res;
    }
};
