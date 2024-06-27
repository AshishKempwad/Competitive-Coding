class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        //Optimal Approach
        /* 1. Store no. of Ones in row and col in a seperate array.
           2. Then no. of 0's in a row = (m - no.of 1's in that row)
           3. no. of 0's in a col = (n - no. of 1's in that col)
           4. Put all the data in the formula and put the computed value in diff matrix.

           TC = O(m*n)
           Sc = O(m*n)
        */

        int n = grid.size();
        int m = grid[0].size();

        vector<int>onesInRow(n,0);
        vector<int>onesInCol(m,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    onesInRow[i]++;
                    onesInCol[j]++;
                }
            }
        }
        vector<vector<int>>diff(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int zerosInRow = m - onesInRow[i];
                int zerosInCol = n - onesInCol[j];
                diff[i][j] = onesInRow[i] + onesInCol[j] - zerosInRow - zerosInCol;
            }
        }

        return diff;

    }
};
