class Solution {
public:
    //Solve it using BFS
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) 
    {
     
         vector<vector<vector<int>>>adj(n);   // To store every node's destination and cost associated with it
        
        for( auto f : flights)
        {
            int s = f[0];
            int d = f[1];
            int cost = f[2];
            
            adj[s].push_back({d,cost});
        }
        
        queue<vector<int>>q;
        q.push({src,0,-1});   // {source, total cost,K);
        //Note : if {A, B} are two directly connected cities, then number of stops b/w them is Zero,
        //so for convenience i'm assuming number of stops b/w A and A as -1
        
        int mincost = INT_MAX;
        
        while(!q.empty())
        {
            vector<int>curr_details = q.front();
            q.pop();
            
            
            int currcity = curr_details[0];
            int total_cost = curr_details[1];
            int currK = curr_details[2];
            
            if(currcity == dst)
            {
                mincost = min(mincost,total_cost);
                continue;
            }

            for(auto x : adj[currcity])
            {
                if(currK+1 <= K && total_cost+x[1] < mincost)
                {
                    q.push({x[0],x[1]+total_cost,currK+1});   
                }
            }
            
            
        }
        
        if(mincost == INT_MAX)
        {
            return -1;
        }
        
        return mincost;
        
    }
};
