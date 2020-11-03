 //IMPORTANT:

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
       map<pair<int,int>,int>row;
       map<pair<int,int>,int>col;
       map<pair<int,int>,int>grid;
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                char res= board[i][j];
                if(board[i][j]!='.')
                {
                    row[{i,res}]++;
                    col[{j,res}]++;
                    int x = (i/3)*3+(j/3);   //to get 3*3 matrix
                    grid[{x,res}]++;
                  
                    if(row[{i,res}] > 1 || col[{j,res}]>1 || grid[{x,res}]>1)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
