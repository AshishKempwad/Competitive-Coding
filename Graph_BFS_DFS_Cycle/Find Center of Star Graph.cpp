/*
Q : There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where 
   there is one center node and exactly n - 1 edges that connect the center node with every other node.
   You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that 
   there is an edge between the nodes ui and vi. Return the center of the given star graph.

Ex : Input: edges = [[1,2],[2,3],[4,2]]
     Output: 2
     Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.

Sol :  It is undirected graph, hence for every edge increase the degree of both the nodes by 1. The node in centre will have edge with every node.
       hence it should have the degree equal to no of total edges
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int noOfEdges = edges.size();
        unordered_map<int,int>degreeMap;

        for(auto &edgeBetween : edges){
              degreeMap[edgeBetween[0]]++;
              degreeMap[edgeBetween[1]]++;
        }

        for(auto &nodes : degreeMap){
            if(nodes.second == noOfEdges){
                return nodes.first;
            }
        }

        return -1;
    }
};
