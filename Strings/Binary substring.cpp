/*Given a binary string, count number of substrings that start and end with 1. 
For example, if the input string is “00100101”, then there are three substrings “1001”, “100101” and “101”.

Task is fining the solution in O(n) time complexity
*/

//Brute force
//Tc=O(n^2)
#include<iostream>    
using namespace std;  
  
int countSubStr(char str[])  
{  
int res = 0; // Initialize result  
  
// Pick a starting point  
for (int i=0; str[i] !='\0'; i++)  
{  
        if (str[i] == '1')  
        {  
            // Search for all possible ending point  
            for (int j=i+1; str[j] !='\0'; j++)  
            if (str[j] == '1')  
                res++;  
        }  
}  
return res;  
} 

----------------------------------------------------------------------------------------------------
  //Optimized solution
  //TC=o(n)
  int countSubStr(char str[]) 
{ 
   int m = 0; // Count of 1's in input string 
  
   // Traverse input string and count of 1's in it 
   for (int i=0; str[i] !='\0'; i++) 
   { 
        if (str[i] == '1') 
           m++; 
   } 
  
   // Return count of possible pairs among m 1's 
   return m*(m-1)/2; 
} 
