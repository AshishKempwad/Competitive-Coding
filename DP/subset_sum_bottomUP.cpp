class Solution {
public:
    
    bool subsetsum(vector<int>& nums,int n,int sum)
    {
        bool dp[n+1][sum+1];
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = 1;     // if sum==0 , fill 1 in table
        }
        for(int i=1;i<=sum;i++)
        {
            dp[0][i] = 0;    //if n==0, fill 0 in table
        }
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1] <= j)  // 
                {
                     //dp[n][sum] = subsetsum(nums,n-1,sum-nums[n-1]) || subsetsum(nums,n-1,sum);
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];  //in bottom up, just replace 'n' with 'i' and 'sum' with 'j'
                }
                else
                {
                 // dp[n][sum] = subsetsum(nums,n-1,sum);
                  dp[i][j] = dp[i-1][j];
                }
            }
        } 
        
        return dp[n][sum];
    }
    
    
    
    
    bool canPartition(vector<int>& nums) 
    {
       int sum=0;
        int n = nums.size();
        int ans;
        sum=accumulate(nums.begin(),nums.end(),sum);
        if(sum%2 != 0)
        {
            return 0;
        }
        else
        {
            
           sum = sum/2;
          
           ans = subsetsum(nums,n,sum);
        }
        return ans;
    }
};
