/*
A permutation, also called an “arrangement number” or “order,” is a rearrangement of the elements
of an ordered list S into a one-to-one correspondence with S itself. A string of length n has n! permutation.
Source: Mathword(http://mathworld.wolfram.com/Permutation.html)

Below are the permutations of string ABC.
ABC ACB BAC BCA CBA CAB
*/

//Algorithm Paradigm: Backtracking
//Time Complexity: O(n*n!) Note that there are n! permutations and it requires O(n) time to print a a permutation.

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

