class Solution {
public:
        /* BRUTE FORCE : 
               Apply BFS from every node where "1" is present till we find "0".
               TC = O((m*n)*(m*n)). -- It would be very bad TC.

           OPTIMIZED APPROACH :
              1)Push coordinates in the queue wherever "0" is present.
              2)Then start applying BFS from 0.
              3) Here, we would be visiting every element only once.    
        */
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        vector<vector<int>>res(n,vector<int>(m,-1));

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    res[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();

            int x = p.first;
            int y = p.second;

            for(int k=0;k<4;k++){
                int x_ = dx[k] + x;
                int y_ = dy[k] + y;

                if(x_ >= 0 && x_ < n && y_ >= 0 && y_ < m && res[x_][y_] == -1){
                    res[x_][y_] = res[x][y] + 1;
                    q.push({x_,y_});
                }
            }
        }

        return res;
    }
};
