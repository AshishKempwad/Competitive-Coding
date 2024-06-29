
class Solution {
public:
    void dfs(int i, int j,int n, int m, vector<vector<char>>& grid){

        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1'){
            return;
        }
        grid[i][j] = '0';
        dfs(i+1,j,n,m,grid);
        dfs(i,j+1,n,m,grid);
        dfs(i-1,j,n,m,grid);
        dfs(i,j-1,n,m,grid);
    }

    void bfs(int i, int j, int n, int m,vector<vector<char>>& grid){

        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};

        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();

            int x = p.first;
            int y = p.second;

            for(int k=0;k<4;k++){
                int x_ = x + dx[k];
                int y_ = y + dy[k];

                if(x_ >= 0 && x_ < n && y_ >= 0 && y_ < m && grid[x_][y_] == '1'){
                    q.push({x_,y_});
                    grid[x_][y_] = '0';
                }
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    //dfs();
                    bfs(i,j,n,m,grid);
                    count++;
                }
            }
        }

        return count;
    }
};
