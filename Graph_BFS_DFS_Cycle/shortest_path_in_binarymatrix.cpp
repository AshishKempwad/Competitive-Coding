class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
       int rows = grid.size();
        int cols = grid[0].size();
        
        int ans = 0;
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(rows,vector(cols,false));
        if(grid.empty())
        {
            return -1;
        }
        
        if(grid[0][0]==1 || grid[rows-1][cols-1]==1)
        {
            return -1;
        }
        
        q.push({0,0});
        vis[0][0]=1;
        int dx[8]={-1,-1,-1,0,0,1,1,1};
        int dy[8]={-1,0,1,-1,1,-1,0,1};
        
        while(!q.empty())
        {
            int z = q.size();
           ans++;
            while(z--)
            {
                
                pair<int,int> temp = q.front();
                q.pop();
                int x = temp.first;
                int y = temp.second;
                if(x==rows-1 && y==cols-1)
                {
                    return ans;
                }
               
               
                for(int i=0;i<8;i++)
                {
                   int x1 = x+dx[i];
                    int y1= y+dy[i];
                    if(x1 >= 0 && x1<rows && y1>=0 && y1<cols && vis[x1][y1]==0 && grid[x1][y1]==0)
                    {
                        vis[x1][y1]=1;
                        q.push({x1,y1});
                        
                    }
                }
            
            }
            
            
        }
        
        return -1;
    }
};
