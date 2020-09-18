int Solution::solve(int A, vector<vector<int> > &B)
{
    vector<vector<pair<int,int>>>graph(A+1);
    
    for(int i=0;i<B.size();i++)
    {
        graph[B[i][0]].push_back({B[i][1],B[i][2]});
        //We are store as :
        // Node (1) -> {Node(2), Cost};
        // Node (2) -> {Node(1) , Cost};
        graph[B[i][1]].push_back({B[i][0],B[i][2]});
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq; //mean heap
    //We create min heap to get the next minimum cost element as required in prims algorithm.
    
    int ans = 0;
    vector<bool>vis(A+1,false);
    vector<int>dist(A+1,INT_MAX);
    
    dist[B[0][0]]=0; //Source
    
    pq.push({0,B[0][0]}); //{cost, node}
    
    while(!pq.empty())
    {
        int curr_cost = pq.top().first;
        int min_index = pq.top().second;
        
        pq.pop();
        
        if(!vis[min_index])  //not visited
        {
            vis[min_index] = true;
            ans = ans + curr_cost;
        }
        
        
        for(auto adj_ele : graph[min_index])
        {
            int adj_ele_index = adj_ele.first;
            int adj_ele_cost = adj_ele.second;
            
            if(dist[adj_ele_index] > adj_ele_cost && !vis[adj_ele_index])
            {
                dist[adj_ele_index] = adj_ele_cost;
                pq.push({dist[adj_ele_index],adj_ele_index});
            }
        }
    }
    
   return ans; 
}
