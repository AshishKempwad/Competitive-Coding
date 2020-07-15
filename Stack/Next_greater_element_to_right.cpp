//Using this code various variations can be done.

vector <long long> nextLargerElement(long long arr[], int n)
{
    vector<long long> ans;
    stack<long long> s;
    
    for(int i=n-1;i>=0;i--)
    {
          while(!s.empty() && arr[i] >= s.top())
          {
	            s.pop();
	        }
	        if(s.empty())
	            ans.push_back(-1);
	        else
	            ans.push_back(s.top());
	        s.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
    // Your code here
}
