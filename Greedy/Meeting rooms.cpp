

    int Solution::solve(vector<vector<int> > &A)
    {
         sort(A.begin(),A.end());
        priority_queue<int,vector<int>,greater<int>>minheap;
        
        minheap.push(A[0][1]);  //Push the end time of first element
        
        for(int i=1;i<A.size();i++)
        {
            if(A[i][0] >= minheap.top())
            {
                minheap.pop(); // That means we can adjust that meeting in the same time slot.
            }
            
            minheap.push(A[i][1]);  //Push the end time of that meeting so we can compare it with next meetings.
        }
        
        return minheap.size();   // The total number of endtimes in heap suggests that, we need that many rooms as
        // all these meetings have overlapping time slots.
    }

