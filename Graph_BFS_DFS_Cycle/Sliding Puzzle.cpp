/*On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.

Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.

Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]

Input: board = [[3,2,4],[1,5,0]]
Output: 14

Note:

    board will be a 2 x 3 array as described above.
    board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].
*/


/*
EXPLANATION

Convert the board from a 2-dimensional representation to a 1-dimensional representation by concatenating the first and second rows. Consider this 1-dimensional representation as the initial root node which is pushed onto a queue q to perform BFS of a "tree" formed by pushing each non-visited next move onto the q ( pushing onto the q can be considered the equivalent of "connecting" the nodes in the "tree" where each candidate is connected as a child one depth below the current node ).

Example "tree":
The nodes are comprised of each candidate string, and nodes are "connected" to each other if they are not already visited and are one move away from each other...

board = {
{ 1,2,3 },
{ 4,0,5 },
};

begin = 123405

depth 0:           123405   <== 0 is at index 4, nextMoves[4]={1,3,5}, so swap 0 with the value
                 /   |    \       at each index 1,3,5 to form the next candidates to be pushed
                /    |     \      onto q in preparation for the next depth of processing
               /     |      \      
depth 1:    103425  123045  123450   <== next candidates pushed onto q
                           (target)

Since BFS is used, all candidates at each depth are checked before proceeding to the next depth. So for this example, depth=1 is returned, since the right-most candidate equals the target value 123450.

*/
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) 
    {
           int res = 0;
        string end = "123450";
        vector<vector<int>> moves = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        // 0 th index p h zero to vo sirf index 1 ya index 3 pe shift ho sakta matrix m and same for rest of index.
        
        string begin = "";
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                begin+=to_string(board[i][j]);
            }
        }
        unordered_set<string> visited;
        visited.insert(begin);
        queue<pair<string, int>> q;
        q.push({begin, 0});
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            string curr = p.first;
            int dist = p.second;
            int idx = curr.find("0");
            if(curr == end)
                return dist;
            for(auto &i : moves[idx]) {
                string next = curr;
                swap(next[idx], next[i]);
                if(!visited.count(next)) {
                    visited.insert(next);
                    q.push({next, dist + 1});
                }
            }
        }
        return -1;
    }
        
    
};
