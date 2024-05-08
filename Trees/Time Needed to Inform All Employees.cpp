class Solution {
public:
    int maxTime = 0;

    void DFS(unordered_map<int,vector<int>>&adj,int currManager,vector<int>& informTime, int currTime){
        maxTime = max(maxTime,currTime);

        for(int &employee : adj[currManager]){
            DFS(adj,employee, informTime,currTime+informTime[currManager]);
        }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {

        //Maintain a map {manager -> {his subordinates}}
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<manager.size();i++){
            
            int employee_i = i;
            int manager_i = manager[employee_i];
            adj[manager_i].push_back(employee_i);
  
        }

        DFS(adj,headID,informTime,0);

        return maxTime;
    }
};
