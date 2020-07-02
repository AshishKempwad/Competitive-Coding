class Solution {
public:
    // This problem is similar to out count of subset with given difference
    
    int target(vector<int>& nums,int n,int sum)
    {
        int dp[n+1][sum+1];
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                count++;
            }
        }
    
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=1;i<=sum;i++)
        {
            dp[0][i] = 0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1]==0)
                {
                    dp[i][j]=dp[i-1][j];
                }
                else if(nums[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return pow(2,count) * dp[n][sum];
    }
    
    
    int findTargetSumWays(vector<int>& nums, int S)
    {
        int n = nums.size();
        int sum=0;
       sum = accumulate(nums.begin(),nums.end(),sum);
        if(S > sum)
        {
            return 0;
        }
        if((sum+S)%2 !=0)
        {
            return 0;
        }
       int new_sum = (sum + S) /2;
        return target(nums,n,new_sum);
    }
};
