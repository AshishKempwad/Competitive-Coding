class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        int GATE = 0;
        int WALL = -1;
        int ROOM = 2147483647;
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rooms[i][j] == GATE){
                    vis[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        
        int steps = 0;
        while(!q.empty()){
           int size = q.size();

           for(int i=0;i<size;i++){
               int x = q.front().first;
               int y = q.front().second;
               q.pop();
               rooms[x][y]=steps;

               for(int k=0;k<4;k++){
                   int newx=x+dx[k];
                   int newy=y+dy[k];

                   if(newx>=0 && newx<n && newy>=0 && newy<m && vis[newx][newy]==false && rooms[newx][newy]==ROOM){
                       vis[newx][newy]=true;
                       q.push({newx,newy});
                   }
               }
           }
           steps++;
        }
    }
};
