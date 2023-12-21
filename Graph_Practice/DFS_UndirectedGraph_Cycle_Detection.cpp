class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool isCycleDFS(vector<int> adj[], vector<bool>&vis, int u, int parent){
        vis[u]=true;
        
        for(auto &v : adj[u]){
            if(v == parent){
                continue;    //As the adjacent element is its parent
            }
            if(vis[v]==true){
                return true;   //That means there's a cycle    
            }
            if(isCycleDFS(adj,vis,v,u)){
                return true;
            }
        }
        
        return false;  //No cycle detected
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i] && isCycleDFS(adj,vis,i,-1)){
                return true;
            }
        }
        
        return false;
        
    }
};
