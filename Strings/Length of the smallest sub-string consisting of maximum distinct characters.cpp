/*Given a string of length N, find the length of the smallest sub-string consisting of maximum distinct characters. Note : Our output can have same character*/

/*Examples:
Input : "AABBBCBB"
Output : 5
Input : "AABBBCBBAC"
Output : 3
Explanation : Sub-string -> "BAC"
Input : "GEEKSGEEKSFOR"
Output : 8
Explanation : Sub-string -> "GEEKSFOR" */


//Brute Force =  TC = O(n^3)


#include <bits/stdc++.h> 
using namespace std; 

int find_distinct(string s,int n)
{
      int freq[256]={0};
      for(int i=0;i<n;i++)
      {
        freq[s[i]]++;
      }
  
      int distinct=0;
  
      for(int i=0;i<256;i++)
      {
        if(freq[i]!=0)
        {
          distinct++;
        }
          
      }
  
  return distinct;
}



int smallesteSubstr_maxDistictChar(string str)
{
  int n = str.size();
  int max_dist = find_distinct(str,n);
  
  int min_len=n;
  
  for(int i=0;i<n;i++)
  {
    
    for(int j=1;j<n;j++)
    {
        string temp = str.substr(i,j);
        int len = temp.size();
        
        int dis = find_distinct(temp,len);
        
        if(dis == max_dist && len < min_len)
        {
          min_len = len;
        }
    
    }
  }
  
  return min_len;
}

/* Driver program to test above function */
int main() 
{ 
    // Input String 
    string str = "GEEKSGEEKSFOR"; 
      
    int len =  smallesteSubstr_maxDistictChar(str); 
    cout << " The length of the smallest substring"
            " consisting of maximum distinct "
            "characters : " << len; 
    return 0; 
}  
