class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void DFS(vector<int> adj[],vector<bool>&vis, int u, vector<int>&res){
        if(vis[u]==true){
            return;
        }
        vis[u]=true;
        res.push_back(u);
        
        for(auto &v : adj[u]){
            if(!vis[v]){
                DFS(adj,vis,v,res);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>res;
        vector<bool>vis(V,false);
        
        DFS(adj,vis,0,res);
        
        return res;
    }
};