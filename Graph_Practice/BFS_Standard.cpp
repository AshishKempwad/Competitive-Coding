//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void BFS( vector<int> adj[], vector<bool>&vis,int u,vector<int>&res){
        queue<int>q;
        
        q.push(u);
        vis[u]=true;
        res.push_back(u);
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(auto &v : adj[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v]=true;
                    res.push_back(v);
                }
            }
        }
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>res;
        vector<bool>vis(V,false);
        
        BFS(adj,vis,0,res);
        
        return res;
    }
};
