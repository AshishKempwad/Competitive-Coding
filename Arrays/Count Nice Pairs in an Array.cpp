class Solution {
public:

    int rev(int num){
        int ans = 0;

        while(num>0){
            int reminder = num%10;
            ans = ans*10+reminder;
            num=num/10;
        }

        return ans;

    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int M = 1e9+7;
         
         //Rearrengement:
        //nums[i] + rev(nums[j]) == nums[j] + rev(nums[i]) => nums[i]-rev(nums[i])==nums[j]-rev(nums[j])

        for(int i=0;i<n;i++){
            nums[i]=nums[i]-rev(nums[i]);
        }

        int result = 0;

        for(int i=0;i<n;i++){
            result = (result+mp[nums[i]])%M;
            mp[nums[i]]++;
        }
        return result;
        
    }

};
