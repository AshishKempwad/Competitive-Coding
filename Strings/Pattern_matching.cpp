/*This question is known by the name of strstr.

Given : Text (A long text)
        Pattern (We need to match this with the text. It is normally smaller than the text)

OUTOUT : Return the index where pattern entirely matches with the text(index of text)*/



//Naive String Matching
// TC = O((n-m+1)*m)  It is quadratic time solution.
//SC : O(constant)

void strstr(string A, string B)
{
    int n = A.size();
    int m = B.size();
    
    for(int i=0;i<=(n-m);i++)
   {
       int count=0;
       for(int j=0;j<m;j++)
       {
          if(A[i+j] == B[j])
          {
            count++;
          }
          else
          {
              break;
          }
       }

       if(count == m-1)
      {

          cout<<i;
      }
   }

}




//Improved Naive
// IMP: (If the pattern given has distinct characters then it can be done in linear time using naive approach)
// TC : Theta(n);
//SC : O(constant)


void strstr(string A, string B)
{
    int n = A.size();
    int m = B.size();
    
    int i=0;
    while(i <= n-m)
   {
      int j;
      for(int j=0;j<m;j++)
      {
         if(A[i+j] != B[j])
         {
            break;
         }
      }

      if(j == m)
     {
        cout<<i;
     }

     if(j==0)
     {
         i++;
     }
     else
     {
      i = i+j;
     }

   }//while

}




//KMP Algorithm
//TC = O(n)
//SC = O(m)

//Phase 1: LPS array creation
//Phase 2: Applying KMP using LPS array


void filllps(string s,vector<int>&LPS)
{
   int m = s.size();
   int len = 0;
   int i=1;
   LPS[0]=0;

   while(i < m)
   {
      if(s[i] == s[len])
      {
         len++;
         s[i] = len;
         i++;
      }
      else
      {
         if(len == 0)
         {
            s[i]=0;
            i++;
         }
         else
         {
            len = LPS[len-1];
         }
         
      }
      
   }
}

void strstr(string A, string B)
{
   int n = A.size();   //Text
   int m = B.size();   //Pattern

   // int LPS[m];
   vector<int>LPS(m);

   if(m > n)
   {
      cout<<"-1";
   }

   filllps(B,LPS);
   int i=0;
   int j=0;
   while(i < n)
   {
      if(A[i] == b[j])
      {
         i++;
         j++;
      }
      if(j==m)
      {
         cout<<i;  // we have found the index where they match and hence we break
         break;
      }
      else if(i<n && A[i]!=B[j])
      {
         if(j==0)
         {
            i++;
         }
         else
         {
           j=lps[j-1];    // Use of LPS array
         }
         
      }
   }

   cout<<"-1";
}

