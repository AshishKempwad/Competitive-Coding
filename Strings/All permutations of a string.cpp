void permutate(string s , int l,int h,vector<string>&res)
{
    if(l == h)
    {
       res.push_back(s);
    }
    
    for(int i=l;i<=h;i++)
    {
        swap(s[l],s[i]);
        permutate(s,l+1,h,res);
        swap(s[l],s[i]); //Backtrack
    }
}

vcetor<int>permutate_all_strings(string s)
{
    if(s.size()==0)
    {
        return {};
    }
    vector<int>res;
    if(s.size()==1)
    {
        res.push_back(s);
        return res;
    }    
    
    permutate(s,0,s.size()-1,res);
    return res;
        
}    

