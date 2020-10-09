/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)


*/



//Brute Force:
//Approach : Take 4 loops
//TC = O(n^4)
//SC = O(1)

----------------------------------------------------------------------------------------------------




//Better Approach :
//TC = O(n^3logn + logn) = O(n^3logn)
//SC = O(n) // used for set

vector<vector<int> > Solution::fourSum(vector<int> &A, int B)
{
    set<vector<int>>s;
    sort(A.begin(),A.end());
    vector<vector<int>>res;
    int n = A.size();
    
    for(int i=0;i<n;i++)
    {
       for(int j=i+1;j<n;j++)
       {
            
            for(int k=j+1;k<n;k++)
            {
                int target = B - (A[i]+A[j]+A[k]);
                
                int l = k+1;
                int h = n-1;
             
                while(h >= l)
                {
                    
                    int mid = (l+h)/2;
                    
                    if(A[mid] > target)
                    {
                        h = mid-1;
                    }
                    else if(A[mid] < target)
                    {
                        l = mid+1;
                    }
                    else
                    {
                      s.insert({A[i],A[j],A[k],target});
                      break;
                    }
                }
            }
            
        }
    
    }
    for(auto x: s)
    {
        res.push_back(x);
    }
    return res;
    
    
}
--------------------------------------------------------------------------------------------------------
//Optimized Approach :
// Take two loops and for binary search for remaining two
//TC = O(n^2logn)
//Sc = O(1)

vector<vector<int> > Solution::fourSum(vector<int> &A, int B)
{
    sort(A.begin(),A.end());
    vector<vector<int>>res;
    int n = A.size();
    
    for(int i=0;i<n;i++)
    {
        if(i==0 || A[i]!=A[i-1])
        {
            for(int j=i+1;j<n;j++)
            {
                if(j==i+1 || A[j]!=A[j-1])
                {
                    int target = B - (A[i]+A[j]);
                    
                    int l = j+1;
                    int h = n-1;
                    
                    while( h > l)
                    {
                        if(A[l]+A[h] > target)
                        {
                            h--;
                        }
                        else if(A[l]+A[h] < target)
                        {
                            l++;
                        }
                        else
                        {
                            res.push_back({A[i],A[j],A[l],A[h]});
                            int curr = A[l];
                            while(l < n && A[l]==curr)
                            {
                                l++;
                            }
                            curr = A[h];
                            while(h >= 0 && A[h]==curr)
                            {
                                h--;
                            }
                        }
                    }
                }
            }
        }
    }
    return res;
}













  
    
