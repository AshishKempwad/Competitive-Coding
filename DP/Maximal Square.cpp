class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        if(matrix.empty())
        {
            return 0;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        int max_area=0;
        vector<vector<int>>dp(rows,vector<int>(cols));
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(i==0 || j==0)   // first row and first coloumn would be either 1 or 0.
                {
                    dp[i][j]=matrix[i][j]-'0';
                }
                else if(matrix[i][j]=='0')    // if the matrix is 0, then we would put 0 as it cannot form a square
                {
                    dp[i][j]=0;
                }
                else if(matrix[i][j]=='1')
                {
                    dp[i][j]= 1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                }
               
                max_area = max(max_area,dp[i][j]);
            }
        }
        
        return max_area*max_area;
    }
};
