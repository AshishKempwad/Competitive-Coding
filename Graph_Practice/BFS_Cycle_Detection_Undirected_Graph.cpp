class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool isCycleBFS(vector<int> adj[], vector<bool>&vis, int u){
        queue<pair<int,int>>q;
        q.push({u,-1});   //{node,parent}
        vis[u]=true;
        
        while(!q.empty()){
           pair<int,int> p = q.front();
           q.pop();
           
           int source = p.first;
           int parent = p.second;
           
           for(auto &v : adj[source]){
               if(vis[v]==false){
                   vis[v]=true;
                   q.push({v,source});
               }
               else if(vis[v]==true && v!=parent){
                   return true;
               }
           }
        }
         return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i] && isCycleBFS(adj,vis,i)){
                return true;
            }
        }
        
        return false;
        
    }
};
