vector<string> generate(ll n)
{
    queue<string> q;
    q.push("1");
    vector<string> res;
    long long count=0;
    while(count < n)
    {
       string curr = q.front();
       q.pop();
       res.push_back(curr);
       q.push(curr+"0");
       q.push(curr+"1");
       count++;
       
    }
    
    return res;
	// Your code here
}
