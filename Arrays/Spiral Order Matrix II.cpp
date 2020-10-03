vector<vector<int> > Solution::generateMatrix(int A) 
{
    vector<vector<int>>grid(A,vector<int>(A));
    int num=1;
    
    int top = 0;
    int down = A-1;
    
    int left = 0;
    int right = A-1;
    
    int dir = 0;
    
    while(down >= top && right >= left)
    {
        if(dir==0)
        {
            for(int i=left;i<=right;i++)
            {
                grid[top][i]=num;
                num++;
            }
            top++;
        }
        else if(dir==1)
        {
            for(int i=top;i<=down;i++)
            {
                grid[i][right]=num;
                num++;
            }
            right--;
        }
        else if(dir==2)
        {
            for(int i=right;i>=left;i--)
            {
                grid[down][i]=num;
                num++;
            }
            down--;
        }
        else if(dir==3)
        {
            for(int i=down;i>=top;i--)
            {
                grid[i][left]=num;
                num++;
            }
            left++;
        }
        
        dir = (dir+1)%4;
    }
    
    return grid;
}
