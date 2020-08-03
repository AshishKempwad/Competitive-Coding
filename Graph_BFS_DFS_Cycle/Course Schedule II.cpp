class Solution {
public:
    
    //The idea is based on topological sorting, using Kahn's Algorithm using BFS
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>>adj(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto x: adj[i])
            {
                indegree[x]++;
            }
        }
        
        queue<int>q;
        
        
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        int count=0;
        vector<int>topo;
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
             count++;
            topo.push_back(u);
            
            for(auto ele : adj[u])
            {
                indegree[ele]--;
                if(indegree[ele]==0)
                {
                    q.push(ele);
                   
                }
                
            }
        }
        
        if(count!=numCourses)
        {
            vector<int>emptyvec;
            return emptyvec;
        }
        
        return topo;
        
    }
};
