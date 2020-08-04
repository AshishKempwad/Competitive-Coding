class Solution {
public:
    
void dfs(vector<vector<int>>&adj,vector<vector<int>>&cost,int src,int dst,int K,vector<bool>&visited,int total_cost_in_curr_iteration,int &fare)
{
    if(K < -1)
    {
        return;
    }
    
    if(src==dst)
    {
        fare = min(fare,total_cost_in_curr_iteration);
        return;
    }
    
    visited[src]=true;
    
    for(auto x : adj[src])
    {
        if(!visited[x]  && (total_cost_in_curr_iteration+cost[src][x] <= fare))
        {
            dfs(adj,cost,x,dst,K-1,visited,total_cost_in_curr_iteration+cost[src][x],fare);
        }
    }
    
    visited[src]=false;
}
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
       vector<vector<int>>adj(n);
        vector<vector<int>>cost(n+1,vector<int>(n+1));
        
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back(flights[i][1]);                //we store the source and destination
            cost[flights[i][0]][flights[i][1]]=flights[i][2];              //we store the cost associated with each edge
        }  
        
        vector<bool>visited(n+1,false);
        int fare = INT_MAX;
        dfs(adj,cost,src,dst,K,visited,0,fare);
        
        if(fare==INT_MAX)
        {
            return -1;
        }
        
        return fare;
    }
};
