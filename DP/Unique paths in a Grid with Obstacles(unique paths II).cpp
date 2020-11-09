/*A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        
        vector<vector<int>>dp(rows,vector<int>(cols,0));
        
        if(obstacleGrid[0][0]==0)   // if starting point has no obstacle then number of paths are 1
        {
            dp[0][0]=1;
        }
        
        for(int i=1;i<rows;i++)
        {
            if(obstacleGrid[i][0]==0)   //if no obstacle
            {
                dp[i][0]=dp[i-1][0];
            }
        }
        
        for(int j=1;j<cols;j++)
        {
            if(obstacleGrid[0][j]==0)   //if no obstacle
            {
               dp[0][j]=dp[0][j-1];
            }
        }
        
        for(int i=1;i<rows;i++)
        {
            for(int j=1;j<cols;j++)
            {
                if(obstacleGrid[i][j]==0)    //if no obstacle
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        
        return dp[rows-1][cols-1];
    }
};
