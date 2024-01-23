//Recursion
class Solution {
public:
    /*At any time we move either right or down to reach the bottom right block*/
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid){
        /*BASE CONDITION
        If we reach the last block of the gird, then we return thr value at that grid*/
        if(i == n-1 && j == m-1){
            return grid[i][j];
        }

        /*If we are at last row, then we cannot move down, we can only move right*/
        if(i == n-1){ 
            return grid[i][j] + solve(i,j+1,n,m,grid);
        }
        else if(j == m-1){
            /*If we are at last columns, then we cannot move right, we can only move down*/
            return grid[i][j] + solve(i+1,j,n,m,grid);

        }else{
            return grid[i][j] + min(solve(i+1,j,n,m,grid), solve(i,j+1,n,m,grid));
        }

    }

    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size(); //rows
        int m = grid[0].size(); //cols

        return solve(0,0,n,m,grid);
        
    }
};

//Recursion + Memo

class Solution {
public:
    
    int dp[201][201];

    /*At any time we move either right or down to reach the bottom right block*/
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid){
        /*BASE CONDITION
        If we reach the last block of the gird, then we return thr value at that grid*/
        if(i == n-1 && j == m-1){
            return grid[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        /*If we are at last row, then we cannot move down, we can only move right*/
        if(i == n-1){ 
            return dp[i][j] = grid[i][j] + solve(i,j+1,n,m,grid);
        }
        else if(j == m-1){
            /*If we are at last columns, then we cannot move right, we can only move down*/
            return dp[i][j] = grid[i][j] + solve(i+1,j,n,m,grid);

        }else{
            return dp[i][j] = grid[i][j] + min(solve(i+1,j,n,m,grid), solve(i,j+1,n,m,grid));
        }

    }

    int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size(); //rows
        int m = grid[0].size(); //cols

        memset(dp,-1,sizeof(dp));
        return solve(0,0,n,m,grid);
        
    }
};
