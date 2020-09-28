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

