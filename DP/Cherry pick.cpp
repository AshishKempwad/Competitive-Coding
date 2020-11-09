class Solution {
public:
    
    //no.of steps = r1+c1 or r2+c2
    // Hence, r1+c1 = r2+c2 , Hence r2 = r1+c1-c2
    
    int helper(int r1,int c1,int c2,int n,vector<vector<vector<int>>>&dp,vector<vector<int>>&grid)
    {
        int r2 = r1+c1-c2;
        
        if(r1==n-1 && c1==n-1)
        {
            return grid[r1][c1];
        }
        if(r1 >= n || c1 >= n || r2 >=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1 )
        {
            return INT_MIN;
        }
        if(dp[r1][c1][c2]!=-1)
        {
            return dp[r1][c1][c2];
        }
        int curr_state = 0;
        
        if(r1==r2 && c1==c2)
        {
            curr_state = grid[r1][c1];   // if both arrive at same place, we choose only once as only one can pick the cherry
        }
        else 
        {
            curr_state = grid[r1][c1]+grid[r2][c2];
        }
        
        int ans=0;
        int ans1 = helper(r1+1,c1,c2,n,dp,grid);
        int ans2 = helper(r1+1,c1,c2+1,n,dp,grid);
        int ans3 = helper(r1,c1+1,c2,n,dp,grid);
        int ans4 = helper(r1,c1+1,c2+1,n,dp,grid);
        
        ans = ans1;
        ans = max(ans,ans2);
        ans=max(ans,ans3);
        ans=max(ans,ans4);
        
        dp[r1][c1][c2]=ans+curr_state;
        
        return dp[r1][c1][c2];
    }
    
    
    
    int cherryPickup(vector<vector<int>>& grid)
    {
       //Rather than going from bottom to up in second iteration, we can go from top to down twice.
        
        int n = grid.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans = max(0,helper(0,0,0,n,dp,grid));
        return ans;
        
    }
};
