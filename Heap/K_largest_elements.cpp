
vector<int> kLargest(int arr[], int n, int k)
{
    vector<int>res;
    priority_queue<int,vector<int>,greater<int>>minheap;
    for(int i=0;i<n;i++)
    {
        minheap.push(arr[i]);
        if(minheap.size() > k)
        {
            minheap.pop();
        }
    }
    
    while(!minheap.empty())
    {
        res.push_back(minheap.top());
        minheap.pop();
    }
    reverse(res.begin(),res.end()); //as we wnat to return the elements in decending order and in minheap we
                                    //have the element such that top element in smaller than the bottom and 
                                    //hence when we pop smallest element comes in front of the vector(i.e ascending order)
    return res;
    
    // code here
}
