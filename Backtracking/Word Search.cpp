class Solution {
public:
         /* THIS IS CLASSIC BACKTRACKING PROBLEM
        1. First check if the word[0] (i.e first character of word) matches with the board[i][j].
        2. We mark it visited by replacing it with "$" or any special character.
        3. We replace the "$" with original character while backtracking.
        */
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    bool find(int i, int j, int n, int m, int idx, vector<vector<char>>& board, string &word){
        if(idx == word.length()){
            return true;
        }

        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '$'){ //If it is out of bound or if it is already visited we return false
            return false;
        }

        if(board[i][j] != word[idx]){ //If the board[i][j] is not equal to current cheracter of the word, we return false
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '$';    //Mark visited with special character

        for(int k=0;k<4;k++){
            int i_ = i + dx[k];
            int j_ = j + dy[k];

            if(find(i_,j_,n,m,idx+1,board,word)){
                return true;
            }
        }

        board[i][j] = temp;     //Replacing special  character with original character while backtracking
        return false;

    }    

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0] && find(i,j,n,m,0,board,word)){
                    return true;
                }
            }
        }

        return false;
    }
};
