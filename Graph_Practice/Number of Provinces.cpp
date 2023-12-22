class Solution {
public:

    void BFS(unordered_map<int,vector<int>>&adj, vector<bool>&visisted, int u, int n){
        queue<int>q;
        q.push(u);

        while(!q.empty()){
            int ele = q.front();
            q.pop();
            
            for(auto &v : adj[ele]){
                if(!visisted[v]){
                    visisted[v]=true;
                    q.push(v);
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {

        //BFS
        unordered_map<int,vector<int>>adj;
        int n = isConnected.size();  //It is n * n matrix
        vector<bool>visisted(n,false);
        //Construction of graph
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;
        for(int i=0;i<n;i++){
            if(!visisted[i]){
                BFS(adj,visisted,i,n);
                count++;
            }
        }
        return count;
    }
};
