/*


You’re given a read only array of n integers. Find out if any integer occurs more than n/3 times in the array in linear time and constant additional space.

If so, return the integer. If not, return -1.

If there are multiple solutions, return any one.

Example :

Input : [1 2 3 1 1]
Output : 1 
1 occurs 3 times which is more than 5/3 times. 


*/

int Solution::repeatedNumber(const vector<int> &A) 
{

    // Brute force:
    // TC = O(n^2)
    // SC = O(1)
    
    //Approach : 1)Take one element and traverse the entire list and if that count > n/3 then that is out answer.
                // 2)Need to do that for every element. 
                 //i.e: Two for loops
    
    
  ---------------------------------------------------------------------------------------------------------------------------  
    
    // Better solution: 
    //TC = O(nlogn) we have used unordered_map.
    //SC = O(n)
    
    
    int n = A.size();
    map<int,int>mp;
    
    for(int i=0;i<n;i++)
    {
        mp[A[i]]++;
    }
    
    int target = n/3;
    unordered_map<int,int>::iterator it; 
    
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        if(it->second > target)
        {
            return it->first;
        }
    }
    return -1;
    
  -------------------------------------------------------------------------------------------------------------------------  
    
    //Optimal solution :
     //TC = O(n)
     //SC = O(1)
     
     //We will use Moore's voting algorithn in modified way
     // We need to know that at max there could be 2 elements whose frequency 
     // could be greater n/3. So here there are 2 candidates in the race.
     
     int n = A.size();
     
     int count1=0;
     int count2=0;
     
     int num1 = INT_MAX;
     int num2 = INT_MAX;
    
    // Step 1 of Moore's voting algorithm of choosing the 2 candidates
    
     for(int i=0;i<n;i++)
     {
         if(A[i] == num1)   //If first candidate
         {
             count1++;
         }
         else if(A[i]==num2) //If second candidate
         {
             count2++;
         }
         else if(count1==0)  // We change the first candidate
         {
             num1=A[i];
             count1=1;
         }
         else if(count2==0)  // We change the second candidate
         {
             num2=A[i];
             count2=1;
         }
         else  // We decrement the count of both
         {
             count1--;
             count2--;
         }
     }
     
     
     //Step 2 of Moore's Voting algorithm is cross checking and validating to see if anyone 
     // of the two is the actual candidate who we are looking for
     count1=0;
     count2=0;
     for(int i=0;i<n;i++)
     {
        if(A[i]==num1)
        {
            count1++;
        }
        else if(A[i]==num2)
        {
            count2++;
        }
     }
     
     if(count1 > n/3)
     {
         return num1;
     }
     
     if(count2 > n/3)
     {
         return num2;
     }
     
     return -1;
     
}
