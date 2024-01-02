class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<int,int>>q;

        //Visit all the surrounding nodes and mark them visited
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(board[i][j] == 'O'){
                        q.push({i,j});
                        vis[i][j]=true;
                    }
                }
            }
        }
        
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};

       //Checking for all 'O' which are adjacent to bordered(surrounding)'O'
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int newx = x+dx[k];
                int newy = y+dy[k];

                if(newx>=0 && newx<n && newy>=0 && newy<m && vis[newx][newy]==0 && board[newx][newy]=='O'){
                    vis[newx][newy]=true;
                    q.push({newx,newy});
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == false && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
