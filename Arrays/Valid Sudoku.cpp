class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /*
           1. Create 3 maps to check uniqueness in row,col and grid.
           2. To find grid use formula => (i/3)*3 + (j/3)
           3. If any of the map has occurance greater than 1 then return false, else return true. 
        */
        map<pair<int,char>,int>rowMap;
        map<pair<int,char>,int>colMap;
        map<pair<int,char>,int>gridMap;

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                char element =  board[i][j];
                if(element != '.'){

                    rowMap[{i,element}]++;
                    colMap[{j,element}]++;

                    int gridNum = (i/3)*3+(j/3);
                    gridMap[{gridNum,element}]++;

                    if(rowMap[{i,element}] > 1 || colMap[{j,element}] > 1 || gridMap[{gridNum,element}] > 1){
                        return false;
                    }
                }
 
            }
        }

        return true;
    }
};
