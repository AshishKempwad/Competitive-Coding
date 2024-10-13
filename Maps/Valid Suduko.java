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

###########################################JAVA##############################

class Solution {
    public boolean isValidSudoku(char[][] board) {

        Map<String,Integer>row = new HashMap<>();
        Map<String,Integer>col = new HashMap<>();
        Map<String,Integer>grid = new HashMap<>();

        int noOfRows = board.length;
        int noOfCols = board[0].length;

        for(int i=0;i<noOfRows;i++){
            for(int j=0;j<noOfCols;j++){

                char ch = board[i][j];

                if(ch != '.'){
                    String rowKey = i + " " + ch;
                    String colKey = j + " " + ch;
                    int gridIndex = (i/3)*3 + (j/3);
                    String gridKey = gridIndex + " " + ch;

                    row.put(rowKey,row.getOrDefault(rowKey,0)+1);
                    col.put(colKey, col.getOrDefault(colKey,0)+1);
                    grid.put(gridKey, grid.getOrDefault(gridKey,0)+1);

                    if(row.get(rowKey) > 1 || col.get(colKey) > 1 || grid.get(gridKey) > 1){
                        return false;
                    }
                }

            }
        }

        return true;



    }
}

