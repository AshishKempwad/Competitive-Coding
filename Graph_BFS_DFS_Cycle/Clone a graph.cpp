/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
//DFS

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

---------------------------------------------------------------------------------------------------------
 
 //BFS
 
 /*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        
        if(node==NULL)
        {
            return NULL;
        }
        unordered_map<Node*,Node*>mp;
        mp[node] = new Node(node->val);
        queue<Node*>q;
        q.push(node);
        
        while(!q.empty())
        {
            Node* old = q.front();
            q.pop();
            
            for(auto neigh : old->neighbors)
            {
                if(!mp.count(neigh))
                {
                    mp[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }
                
                Node* newnode = mp[old];
                // Node* newnodeneigh = mp[neigh];
                newnode->neighbors.push_back(mp[neigh]);
            }
        }
        
        return mp[node];
        
    }
};
