class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        long long n = nums.size();
        long long result = 0;

        unordered_map<long long,long long>mp[n];  //This is not single map, this is array of map
        /* It is array of map. Each map has {key,value} Here key = diff and values = freqency */

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
             
                /*We compute the difference between two elements at index i and j*/
                long long diff = (long long)nums[i] - nums[j];

                long long count_at_j;

                /*We check in our array of map, if at index j of array, if we have a map with key of current diff
                If such key is present in map then thats our count till "j", else its 0(meaning we dont have any subseqence till "j")*/

                if(mp[j].find(diff) != mp[j].end()){
                    count_at_j = mp[j][diff]; 
                }else{
                    count_at_j = 0;
                }

                //Update the map ending at index "i" based on count ending at index "j"
                mp[i][diff] += count_at_j + 1;

                result += count_at_j;  
            }
        }
        return result;
    }
};
