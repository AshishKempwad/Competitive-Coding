int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B)
{
    int min_moves = 0;
    
    unordered_map<int,int>mp;
    for(auto x: A)
    {
        mp[x[0]] = x[1];
    }
    for(auto x: B)
    {
        mp[x[0]] = x[1];
    }
    
    vector<bool>vis(101,false);
    queue<int>q;
    q.push(1);
    
    while(!q.empty())
    {
        int qsize = q.size();
        
        for(int i=0;i<qsize;i++)
        {
            int pos = q.front();
            q.pop();
            
            if(pos == 100)
            {
                return min_moves;
            }
            
            if(vis[pos]==false)
            {
                vis[pos]=true;
                
                for(int j=1;j<=6;j++)
                {
                    int loc = pos + j;
                    if(loc <= 100)
                    {
                        if(mp.find(loc) != mp.end())
                        {
                            loc = mp[loc];
                            
                        }
                        q.push(loc);
                    }
                    
                }
            }
            
        }
        
        min_moves++;
    }
    
    return -1;
    
}

##################################LEETCODE JAVA##################################
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


