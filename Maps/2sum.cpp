vector<int> Solution::twoSum(const vector<int> &A, int B)
{
    vector<pair<int,int>>res;
    unordered_map<int,int>mp;
    for(int i=0;i<A.size();i++)
    {
        if(mp.find(B-A[i])!=mp.end())
        {
            return {mp[B-A[i]]+1,i+1};
        }
        mp.insert({A[i],i});
    }
    
    return {};
    
}
