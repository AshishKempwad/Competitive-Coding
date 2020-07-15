queue<long long int> rev(queue<long long int> q)
{
    long long int n = q.size();
    stack<long long int> s;
    for(long long int i =0;i<n;i++)
    {
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    
    return q;
    // add code here.
}
