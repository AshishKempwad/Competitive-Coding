/*
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), 
where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2
*/


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) 
    {
        vector<vector<pair<int,int>>>graph(N,vector<pair<int,int>>());
        K--;   // out indexing starts from 0
        
        for(int i=0;i<times.size();i++)
        {
            int u = times[i][0]-1;   // source node // indexing starts from 0 
            int v = times[i][1]-1;
            int cost = times[i][2];
            
            graph[u].push_back({v,cost});  // structure {destination,cost to reach destination from source}
            
        }
        
        vector<int>dist(N,1001);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;  // to get the minimum element
        
        dist[K]=0;  // we start from source, and distance from source to source is 0
        minheap.push({0,K});    // structure of minheap elements, {cost,node}
        pair<int,int>node;
        while(!minheap.empty())
        {
            node=minheap.top();
            minheap.pop();
            
            int u = node.second;
            int cost = node.first;
            
            for(int i=0;i<graph[u].size();i++)
            {
                int v = graph[u][i].first;
                int new_cost = graph[u][i].second + cost;
                
                if(new_cost < dist[v])   // if theres a path through this node whose overall value is less then we update that
                {
                    dist[v]=new_cost;
                    minheap.push({new_cost,v});
                }
                
            }
            
        }
        
  int cost = -1;
        for(int i = 0; i < N; i++){
            cost = max(dist[i], cost);
        }
        return cost != 1001 ? cost : -1;
        
        
    }
};
