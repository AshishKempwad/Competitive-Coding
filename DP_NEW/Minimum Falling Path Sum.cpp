//Brute (DP) - It pass 49/50 testcases

class Solution {
public:
    int dp[101][101];
    int solve(int row, int col, int n, vector<vector<int>>& matrix){
        if(row == n-1){
            return matrix[row][col];  //If at last row, return that value
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int sum = matrix[row][col];
        int minSum = INT_MAX;
       if(row+1 < n && col+1 < n && col+1 >=0){
           minSum = min(minSum, sum + solve(row+1,col+1,n,matrix));
       }
       if(row+1 < n && col < n && col >=0){
           minSum = min(minSum, sum + solve(row+1,col,n,matrix));
        }
        if(row+1 < n && col-1 < n && col-1 >=0){
           minSum = min(minSum, sum + solve(row+1,col-1,n,matrix));
        }

        return dp[row][col] = minSum;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int row = 0;
        int result = INT_MAX;
        memset(dp,-1,sizeof(dp));

        for(int col = 0;col<n;col++){
            result = min(result, solve(row,col,n,matrix));
        }
        return result;
    }
};

//Optimal Solution:
class Solution {
public:

    /*The idea is simple here, we compute the minimum of the 3 from 
    last step and add that to the current block. And eventually return the minimum from the last row of the matrix*/

    int minFallingPathSum(vector<vector<int>>& matrix) {
        //It is n*n matrix
        int n = matrix.size();
        int result = INT_MAX;

        /*Create a 2D matrix of similar size of that os the given matrix*/
        vector<vector<int>>temp(n,vector<int>(n)); 

        /*First row remains same in the newly created temp vector.
        Copy contents of first row from matrix(given 2D array into newly created 2D array)*/
         
        for(int col=0; col<n; col++){
            temp[0][col] = matrix[0][col];
        }

        for(int row=1;row<n;row++){
            for(int col=0;col<n;col++){
                int a = INT_MAX;
                int b = INT_MAX;
                int c = INT_MAX;

                if(col-1 >= 0){
                    a = temp[row-1][col-1];
                }
                b = temp[row-1][col];
                if(col+1 < n){
                    c = temp[row-1][col+1];
                }
                temp[row][col] = matrix[row][col] +  min({a,b,c});
            }
        }

        /*We need to return minimum of last row from the temp array*/
        int lastRow = n-1;
        for(int col=0;col<n;col++){
            result = min(result,temp[lastRow][col]);
        }

        return result;
    }
};
