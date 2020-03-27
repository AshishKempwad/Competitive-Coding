#include<bits/stdc++.h>
using namespace std;
/*
We perform swap only between current and its next consecutive bit as anything more than that would cost alot as the cost is |i-j| 
and hence in such case flip would be better option and flip costs only 1. We will use skip only when..
eg: S = 1 0
    t = 0 1
    here we can swap easily and after swapping the digits would be both same i.e S == t.

*/
int main()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int cost=0;

    for(int i=0;i<n;)
    {

        if(s[i]!=t[i])
        {
            if((i+1 < n) && s[i+1]!=t[i+1] && s[i]!=s[i+1] && t[i]!=t[i+1])
            {
                //swap
                cost++;
                i=i+2; //we skip the two consecutive digits as both have been swapped
            }
            else
            {
                i++; //we skip only one digit as only that bit/digit has been flipped
                cost++;
            }
        }
        else
        {
            i++;
        }
    }
    cout<<cost<<endl;
    return 0;
}
