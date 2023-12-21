class Solution {
public:

    bool topologicalSortCheck(unordered_map<int,vector<int>> &adj,vector<int>&indegree,int n){
           
           queue<int>q;
           int count=0;
           for(int i=0;i<n;i++){
               if(indegree[i] == 0){
                   count++;
                   q.push(i);
               }
           }

           while(!q.empty()){
               int u = q.front();
               q.pop();

               for(auto &v : adj[u]){
                    indegree[v]--;

                    if(indegree[v]==0){
                        q.push(v);
                        count++;
                    }
               }
           }

           if(count==n){
               return true;    //If we are able to visit all the nodes, that means we can complete all the courses
           }

           return false;
    }
   
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int,vector<int>> adj;
        vector<int>indegree(numCourses,0);

        for(auto &ele : prerequisites){
            int a = ele[0];
            int b = ele[1];
            // a --->b
            adj[b].push_back(a);  // Inorder to complete the course "b", I have to first complete the course "a". 
                                 // [a,b] Here there is a directed line from b->a
            indegree[a]++;
        }

       //If there is a cycle we return false. i.e[We cant complete all the courses if there is a cycle]
        return topologicalSortCheck(adj,indegree,numCourses);
    }
};
