string find_prefix(string s1,string s2)
{
    int n = s1.size();
    int m = s2.size();
    string result;
    
    for(int i=0,j=0; i<n && j<m ; i++,j++)
    {
        if(s1[i]!=s2[j])
        {
            break;
        }
        
        result.push_back(s1[i]);
    }
    // cout<<result;
    return result;
}

string compute(vector<string>s,int n)
{
    string prefix=s[0];
   
    for(int i=1;i<n;i++)
    {
        prefix = find_prefix(prefix,s[i]);
    }
 
    return prefix;
    
}
