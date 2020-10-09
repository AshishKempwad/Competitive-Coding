   vector<map<int,int>>row(9);
        vector<map<int,int>>col(9);
        vector<map<int,int>>grid(9);
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                char res = board[i][j];
                if(board[i][j]!='.')
                {
                    row[i][res]++;
                    col[j][res]++;
                    grid[(i/3)*3+(j/3)][res]++;        //(i/3)*3+(j/3) gives the reuired 3*3 grid
                    
                    if(row[i][res] > 1 || col[j][res] > 1 || grid[(i/3)*3 + (j/3)][res] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
