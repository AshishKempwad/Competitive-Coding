vector <int> nearlySorted(int arr[], int num, int K)
{
    vector<int>res;
    priority_queue<int,vector<int>,greater<int>>minheap;
    for(int i=0;i<num;i++)
    {
        minheap.push(arr[i]);
        if(minheap.size() > K)
        {
            res.push_back(minheap.top());
            minheap.pop();
        }
    }
    
    while(minheap.size()>0)
    {
        res.push_back(minheap.top());
        minheap.pop();
    }
    
    return res;
    // Your code here
}
