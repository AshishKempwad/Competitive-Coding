class Solution {
public:

    void dfs(int u, vector<int>&vis, unordered_map<int,vector<int>>&adj){
        vis[u] = true;

        for(auto &v : adj[u]){
            if(vis[v] == false){
                dfs(v,vis,adj);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        //Approach
        /* 1. Reverse the directed graph
           2. Apply DFS
        */

        unordered_map<int,vector<int>>adj;
        vector<vector<int>>res;

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);   //v--->u - Reversing the directed graph
        }

        for(int u=0;u<n;u++){
            vector<int>vis(n,false);
            vector<int>anscestors;

            dfs(u,vis,adj);

            for(int i=0;i<n;i++){
                if(vis[i] == true && i!=u){
                     anscestors.push_back(i);
                }
            }
            res.push_back(anscestors);
        }

        return res;
    }

    
};
