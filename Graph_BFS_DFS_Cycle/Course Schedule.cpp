class Solution {
public:
    
    bool DFSrec(vector<vector<int>>& graph,vector<bool>&vis,vector<bool>&recst,int s)
    {
        vis[s]=true;
        recst[s]=true;
        
        for(int i=0;i<graph[s].size();i++)
        {
            int u =graph[s][i];
            if(!vis[u] && DFSrec(graph,vis,recst,u))
            {
                return true; //there is cycle
            }
            else if(recst[u])
            {
                return true; //it is already visited
            }
        }
        
        recst[s]=false;
        return false; //no cycle
    }
    
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<bool> vis(numCourses,false);
        vector<bool> recst(numCourses,false);
        
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(DFSrec(graph,vis,recst,i))
                {
                    return false; //as there is a cycle we cannot complete courses
                }
            }
        }
        
        return true;
    }
};
