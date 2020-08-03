
// Will solve it using Kahn's algorithm over BFS

vector<int> topoSort(int V, vector<int> adj[])
{
    
    vector<int>indegree(V,0);   // to calculate indegree of every vertex
    
    /*We calculate indegree of nodes*/
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        {
            int node = adj[i][j];
            indegree[node]++;
        }
    }
    
    /*Push all the nodes with indegree zero*/
    queue<int>q;
    
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
  
    vector<int>topological_order;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        topological_order.push_back(u);
        
       for(auto ele : adj[u])
       {
           indegree[ele]--;
           if(indegree[ele]==0)
           {
               q.push(ele);
            //   count++;
           }
       }
       
    }
    
    return topological_order;
    
 
    // Your code here
}
