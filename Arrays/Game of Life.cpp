class Solution {
public:
    //Checking all 8 neighbours
    int getLiveNeighbours(int n, int m, int i, int j, vector<vector<int>>& board){
        //Check the bound and count live neighbours
        int liveNeighbours = 0;

        if(i-1 >= 0 && j-1>=0 && (board[i-1][j-1] == 1 || board[i-1][j-1] == 3)){
           liveNeighbours++;
        }
        if(i-1 >= 0 && (board[i-1][j]==1 || board[i-1][j]==3)){
            liveNeighbours++;
        }
        if(i-1 >= 0 && j+1 < m && (board[i-1][j+1] == 1 || board[i-1][j+1] == 3)){
            liveNeighbours++;
        }
        if(j-1 >= 0 && (board[i][j-1] == 1 || board[i][j-1] == 3)){
            liveNeighbours++;
        }
        if(j+1 < m && (board[i][j+1] == 1 || board[i][j+1] == 3 )){
            liveNeighbours++;
        }
        if(i+1 < n && j-1 >= 0 && (board[i+1][j-1] == 1 || board[i+1][j-1] == 3)){
            liveNeighbours++;
        }
        if(i+1 < n && (board[i+1][j] == 1 || board[i+1][j] == 3)){
            liveNeighbours++;
        }
        if(i+1 < n && j+1 < m && (board[i+1][j+1] == 1||board[i+1][j+1] == 3)){
            liveNeighbours++;
        }

        return liveNeighbours;

    }

    void gameOfLife(vector<vector<int>>& board) {

        int n = board.size();
        int m = board[0].size();

        /* Logic : Just mark newly alive and newly dead
           0 - Dead
           1 - Alive
           2 - Newly Alive - if ut has exactly 3 live neighbours
           3-  Newly Dead - Due to overpopulation or underpopulation
        */

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int liveNeighbours = getLiveNeighbours(n,m,i,j,board);

                if(board[i][j] == 0){ //dead in current state
                   if(liveNeighbours == 3){
                    board[i][j] = 2; //newly alive
                   }

                }else if(board[i][j] == 1){ //Alive in current state
                   if(liveNeighbours < 2 || liveNeighbours > 3){
                    board[i][j] = 3;  //newly dead due to underpopulation or overpopulation
                   }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 2){
                    board[i][j] = 1;
                }
                else if(board[i][j] == 3){
                    board[i][j] = 0;
                }
            }
        }
    }
};
