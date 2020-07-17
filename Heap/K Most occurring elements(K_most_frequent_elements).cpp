// Function to print the k numbers with most occurrences 

//Print the count of such numbers

int print_N_mostFrequentNumber(int arr[],int n, int k) 
{ 
    
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    
    priority_queue<int,vector<int>,greater<int>>minheap;
    
    for(auto i=mp.begin();i!=mp.end();i++)
    {
        minheap.push(i->second);
        if(minheap.size() > k)
        {
            minheap.pop();
        }
    }
    
    int count=0;
    while(!minheap.empty())
    {
        count = count + minheap.top();
        minheap.pop();
    }
    
    return count;
	// Your code here	 
}
