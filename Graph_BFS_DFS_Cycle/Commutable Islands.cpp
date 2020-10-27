/*
There are A islands and there are M bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

Input Format:

The first argument contains an integer, A, representing the number of islands.
The second argument contains an 2-d integer matrix, B, of size M x 3:
    => Island B[i][0] and B[i][1] are connected using a bridge of cost B[i][2].

Output Format:

Return an integer representing the minimal cost required.

Constraints:

1 <= A, M <= 6e4
1 <= B[i][0], B[i][1] <= A
1 <= B[i][2] <= 1e3

Examples:

Input 1:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 4]
            [1, 4, 3]
            [4, 3, 2]
            [1, 3, 10]  ]

Output 1:
    6

Explanation 1:
    We can choose bridges (1, 2, 1), (1, 4, 3) and (4, 3, 2), where the total cost incurred will be (1 + 3 + 2) = 6.

Input 2:
    A = 4
    B = [   [1, 2, 1]
            [2, 3, 2]
            [3, 4, 4]
            [1, 4, 3]   ]

Output 2:
    6

Explanation 2:
    We can choose bridges (1, 2, 1), (2, 3, 2) and (1, 4, 3), where the total cost incurred will be (1 + 2 + 3) = 6

*/

//TC=(ElogV)

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
