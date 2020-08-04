/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>mp;  
 
UndirectedGraphNode *dfs(UndirectedGraphNode *node)
{
    if(node==NULL)
    {
        return NULL;
    }
    
    if(mp.find(node)==mp.end())
    {
       mp[node] = new UndirectedGraphNode(node->label);
       for(auto x : node->neighbors)
       {
          mp[node]->neighbors.push_back(dfs(x));
       }
    }
    
   return mp[node];
    
    
}
 

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) 
{
    mp.clear();
    return dfs(node);
}
