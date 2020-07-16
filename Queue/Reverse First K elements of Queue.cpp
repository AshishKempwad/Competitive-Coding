queue<ll> modifyQueue(queue<ll> q, int k)
{
    queue<ll>q1;
    stack<int>s;
    while(k--)
    {
        q1.push(q.front());
        q.pop();
    }
    
    while(!q1.empty())
    {
        s.push(q1.front());
        q1.pop();
    }
    
    while(!s.empty())
    {
        q1.push(s.top());
        s.pop();
    }
    while(!q.empty())
    {
        q1.push(q.front());
        q.pop();
    }
    
    return q1;
    //add code here.
}
