class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        /* 1. Find degree of each node
           2. Node with highest degree gets largest node value
        */

        vector<int>degree(n,0);
        long long int maxImportanace = 0;

        for(auto &edges : roads){
            degree[edges[0]]++;
            degree[edges[1]]++;
        }

        sort(begin(degree),end(degree));

        for(int i=0;i<n;i++){
            maxImportanace += (long long int)(degree[i])*(i+1);
        }

        return maxImportanace;

    }
};
