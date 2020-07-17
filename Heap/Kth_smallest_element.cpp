int kthSmallest(int arr[], int n, int k)
{
    priority_queue<int> maxheap;
    for(int i=0;i<n;i++)
    {
        maxheap.push(arr[i]);
        if(maxheap.size() > k)
        {
            maxheap.pop();
        }
    }
    
    return maxheap.top();
    // Your code here
}
