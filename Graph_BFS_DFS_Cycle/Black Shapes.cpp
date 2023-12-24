int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
void dfs(vector<string> &A,int x,int y,int n,int m)
{
   A[x][y]='N';
   
   for(int i=0;i<4;i++)
   {
       int newx = x + dx[i];
       int newy = y + dy[i];
       
       if(newx >=0 && newx < n && newy >= 0 && newy < m && A[newx][newy]=='X')
       {
           dfs(A,newx,newy,n,m);
       }
       
   }
}


int Solution::black(vector<string> &A)
{
    int count = 0;
    int n = A.size();
    int m = A[0].size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]=='X')
            {
                dfs(A,i,j,n,m);
                count++;
            }
        }
    }
    
    return count;
    
    
}

-----------------------------------------------------------------------------------------------------------------

int Solution::black(vector<string> &A) {
    
    int n = A.size();
    int m = A[0].size();
    int count=0;
    queue<pair<int,int>>q;
    vector<int>dx = {0,1,-1,0};
    vector<int>dy = {1,0,0,-1};
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            if(A[i][j]=='X' && vis[i][j]==false){
                q.push({i,j});
                vis[i][j]=true;
                count++;
                
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for(int k=0;k<4;k++){
                        int newx = x + dx[k];
                        int newy = y + dy[k];
                        
                        if(newx >= 0 && newx < n && newy >=0 && newy < m && A[newx][newy]=='X' && vis[newx][newy]==false){
                            vis[newx][newy]=true;
                            q.push({newx,newy});
                        }
                    }
                }
            }
        }
    }
    
    return count;
}



