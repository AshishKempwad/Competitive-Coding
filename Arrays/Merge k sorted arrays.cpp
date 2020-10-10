/*
You are given K sorted integer arrays in a form of 2D integer matrix A of size K X N.
You need to merge them into a single array and return it.

Example Input

Input 1:

 A = [  [1, 2, 3]
        [2, 4, 6]
        [0, 9, 10]
     ]



Example Output

Output 1:

 [0, 1, 2, 2, 3, 4, 6, 9, 10]


*/
//TC = O(n*klogk)  where, 'k' is the number of sorted arrays and 'n' is the size of each sorted array.
//SC = O(k)

vector<int> Solution::solve(vector<vector<int> > &A)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<int>res;
    for(int i=0;i<A.size();i++)
    {
        pq.push({A[i][0],{i,0}});  //Structure :  {element,{row,col}}
        
    }
    
    while(!pq.empty())
    {
        auto pick = pq.top();
        res.push_back(pick.first);
        pq.pop();
        
        if(pick.second.second  < A[0].size()-1)
        {
            pq.push({A[pick.second.first][pick.second.second+1],{pick.second.first,pick.second.second+1}});
        }
        
    }
    
    return res;
}
