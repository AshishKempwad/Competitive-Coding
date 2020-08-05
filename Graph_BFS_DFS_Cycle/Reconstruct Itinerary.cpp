class Solution {
public:
    
    //In this problem choice of data structures is very very important
    
    //DATA STRUCTURES
    
    //1)We will use unordered_map to create adjacency list in place of vector2
    //2)We need the places in lexographical manner hence, we will use multiset in map,rather than vector
    //3)Will use stack to maintain the ordering
    
    
    
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        unordered_map<string,multiset<string>>adj;  //We use multiset, in place of set because, it can handle duplicates in sorted manner
        
        vector<string>res;
        int n = tickets.size();

    
         for(int i=0;i<n;i++)
         {
             adj[tickets[i][0]].insert(tickets[i][1]);
         }
        
        stack<string> st;
        
        st.push("JFK");   //JFK is our fixed starting point
        
        while(!st.empty())
        {
            string src = st.top();
            
            if(adj[src].size()==0)   //no more places to visit from this point
            {
                res.push_back(src);
                st.pop();
            }
            else
            {
                auto dst = adj[src].begin();
                st.push(*dst);
                adj[src].erase(dst);
            }
            
        }
        
        reverse(res.begin(),res.end());
        
        return res;
        
        
    }
};
