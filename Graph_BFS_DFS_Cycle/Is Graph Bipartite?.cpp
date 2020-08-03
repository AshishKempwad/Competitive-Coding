class Solution {
public:
    
    bool bipartite(vector<vector<int>>& graph, vector<int>&color,int curr)
    {
        color[curr] = 1;
        queue<int>q;
        q.push(curr);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
                
            for(auto x : graph[node])
            {
                if(color[x]==-1)
                {
                    color[x] = 1 - color[node] ;
                    q.push(x);
                }
                else if(color[x]==color[node])                    //color of adjacent nodes match
                {
                    return false;
                }
            }
        }
        
        return true;                              //graph is a bipartite
    }
    

    bool isBipartite(vector<vector<int>>& graph) 
    {
      
        int n = graph.size();
        vector<int>color(n,-1);
        
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)        //still not colored
            {
                if(!bipartite(graph,color,i))
                {
                    return false;     // not a bipartite graph
                }
            }
        }
        
        return true;    // it is a bipartite graph
        
        
    }
};
