class Solution {
public:
    
    //We solve it using the approach of Graph coloring by method of BFS
    
    bool bipartite(vector<vector<int>>&adj,int curr,vector<int>&color)
    {
        queue<int>q;
        q.push(curr);
        
        color[curr]=1;                            //we chose two colors '1' and '0'
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            
            for(int ele : adj[u])
            {
                if(color[ele]==color[u])  // partition not possible according to graph coloring
                {
                    return false;
                }
                if(color[ele] == -1)
                {
                    color[ele] = 1 - color[u];
                    q.push(ele);
                }
            }
        }
        
        return true;                            //partition possible
    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) 
    {
        vector<vector<int>>adj(N+1);
        
        for(int i=0;i<dislikes.size();i++)                      //create adjacency list
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int>color(N+1,-1);
        
        for(int i=1;i<=N;i++)
        {
            if(color[i]==-1)
            {
                if(!bipartite(adj,i,color))    //if we cannot form the partition
                {
                    return false;
                }
            }
        }
        
        return true;                       // we can partition
    }
};
