/*
Given any source point, (C, D) and destination point, (E, F) on a chess board, we need to find whether Knight can move to the destination or not.

Knight's movements on a chess board

The above figure details the movements for a knight ( 8 possibilities ).

If yes, then what would be the minimum number of steps for the knight to move to the said point.
If knight can not move from the source point to the destination point, then return -1.

Note: A knight cannot go out of the board.



Input Format:

The first argument of input contains an integer A.
The second argument of input contains an integer B.
    => The chessboard is of size A x B.
The third argument of input contains an integer C.
The fourth argument of input contains an integer D.
    => The Knight is initially at position (C, D).
The fifth argument of input contains an integer E.
The sixth argument of input contains an integer F.
    => The Knight wants to reach position (E, F).
Output Format:

If it is possible to reach the destination point, return the minimum number of moves.
Else return -1.

*/
int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int Solution::knight(int A, int B, int C, int D, int E, int F)
{
    if(C == E && D==F)
    {
        return 0;
    }
    vector<vector<bool>>vis(A+1,vector<bool>(B+1,0));
    vis[C][D]=1;
    
    queue<pair<int,int>>q;
    
    q.push({C,D});
    int count=0;
    
    while(!q.empty())
    {
        int n = q.size();
        
        for(int i=0;i<n;i++)
        {
            pair<int,int>temp = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;
            
            for(int i=0;i<8;i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                
                if(newx > 0 && newx <= A && newy > 0 && newy <= B && vis[newx][newy]==0)
                {
                    if(newx == E && newy == F)
                    {
                        return count+1;
                    }
                    vis[newx][newy]=1;
                    q.push({newx,newy});
                }
            }
        }
        
        count++;
    }
    
    return -1;  
}
