int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

bool dfs(int x,int y,int pos,vector<string>&A,string B)
{
    if(pos == B.size())
    {
        return 1;
    }
    if(x < 0 || y < 0 || x >= A.size() || y >= A[0].size() || A[x][y]!=B[pos])
    {
        return 0;
    }
    pos++;
    for(int i=0;i<4;i++)
    {
        int newx = x + dx[i];
        int newy = y + dy[i];
        
        if(dfs(newx,newy,pos,A,B))
        {
            return true;
        }
    }
    return false;
}



int Solution::exist(vector<string> &A, string B) 
{
    if(A.empty())
    {
        return 0;
    }
    if(B.empty())
    {
        return 1;
    }
    
    int n = A.size();
    int m = A[0].size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==B[0])
            {
                if(dfs(i,j,0,A,B))
                {
                    return 1;
                }
            }
        }
    }
    
    return 0;
}
