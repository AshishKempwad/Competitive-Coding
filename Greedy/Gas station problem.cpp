int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B)
{
    int surplas = 0;
    int deficiet = 0;
    int index=0;
    int n = A.size();
    
    for(int i=0;i<n;i++)
    {
        surplas = surplas + (A[i] - B[i]);
        
        if(surplas < 0)
        {
            deficiet = deficiet + surplas;
            surplas = 0;
            index = i+1;
        }
    }
    
    if(surplas + deficiet >=0)
    {
        return index;
    }
    
    return -1;
}
