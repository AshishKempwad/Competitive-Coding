class Solution {
public:

   int n;

    pair<int,int>getCoOrdinates(int num){

        int RowFromTop = (num-1)/n;
        int RowFromBottom = (n-1) - RowFromTop;

        int Col = (num-1)%n;  //LeftToRight
        
        if((n%2 == 0 && RowFromBottom%2 == 0) || (n%2==1 && RowFromBottom%2==1)){ //RightToLeft
             Col = (n-1) - Col;
        }

        return make_pair(RowFromBottom,Col);

    }


    int snakesAndLadders(vector<vector<int>>& board) {
        //It is n*n matrix. Hence no of rows == no of cols

        n = board.size(); //Same no. of rows and cols (as it is n*n matrix)
        queue<int>q;
        q.push(1);
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vis[n-1][0]=true; //Starting from bottom left
        int steps = 0;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                int x = q.front();
                q.pop();
                if(x == n*n){ //Reached final block
                    return steps;
                }

                for(int k=1;k<=6;k++){ //range of movements
                    int val = x+k;

                    if(val > n*n){ //If we go out of bound, then we just break
                        break;
                    }

                    pair<int,int>coOrdinates = getCoOrdinates(val);
                    int r = coOrdinates.first;
                    int c = coOrdinates.second;

                    if(vis[r][c] == true){ //If already visited, then continue
                          continue;
                    }

                    vis[r][c] = true;

                    if(board[r][c] == -1){ //If -1 then check in range
                        q.push(val);
                    }else{
                        q.push(board[r][c]);  //It could be snake or ladder, move to the position directly
                    }
                }
            }

            steps++;
        }

        return -1; //If there is no way we can reach the last block
    }
};


######################################## JAVA ######################################

// TC = SC = O(n^2)


import java.util.*;

class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length;
        int[] moves = new int[n * n + 1]; // To store the adjusted positions (ladders or snakes)

        // Flatten the board into a 1D array
        int index = 1;
        boolean leftToRight = true;
        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++) {
                    moves[index++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    moves[index++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;
        }

        // Start BFS from position 1
        Queue<Integer> queue = new LinkedList<>();
        queue.add(1);
        boolean[] visited = new boolean[n * n + 1];
        visited[1] = true;
        int steps = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            // Process each level of BFS (number of dice rolls)
            for (int i = 0; i < size; i++) {
                int current = queue.poll();
                if (current == n * n) {
                    return steps; // Reached the final cell
                }

                // Explore all next possible moves with the dice roll (1 to 6)
                for (int dice = 1; dice <= 6; dice++) {
                    int next = current + dice;
                    if (next > n * n) break; // Out of bounds

                    // Check if there is a ladder or snake at the next position
                    if (moves[next] != -1) {
                        next = moves[next];
                    }

                    // Add the new position to the queue if not visited
                    if (!visited[next]) {
                        visited[next] = true;
                        queue.add(next);
                    }
                }
            }
            steps++;
        }

        return -1; // If the destination is not reachable
    }
}


