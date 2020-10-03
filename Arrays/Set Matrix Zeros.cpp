/*Given a matrix, A of size M x N of 0s and 1s. If an element is 0, set its entire row and column to 0.

Note: This will be evaluated on the extra memory used. Try to minimize the space and time complexity.


Input 1:
    [   [1, 0, 1],
        [1, 1, 1], 
        [1, 1, 1]   ]

Output 1:
    [   [0, 0, 0],
        [1, 0, 1],
        [1, 0, 1]   ]

Input 2:
    [   [1, 0, 1],
        [1, 1, 1],
        [1, 0, 1]   ]

Output 2:
    [   [0, 0, 0],
        [1, 0, 1],
        [0, 0, 0]   ]

*/








//Brute Force : It would require, TC = O(M*N)*(M+N)
                                  //SC = O(1)
                                  
                                  /*Approach: 1)Traverse the entire matrix and wherever you find any '0' make its entire row and col as '-1'
                                            2) Traverse the entire matrix and wherever we see -1 make it as 0.  */
                                            
------------------------------------------------------------------------------------------------------------------------------------------                                            

//Better Approach :
                   //TC = O(M*N)
                   //SC = O(M+N)
                   
void setzero(vector<vector<int> > &A)
{
   bool row[A.size()]={0};
   bool col[A[0].size()]={0};
   
   for(int i=0;i<A.size();i++)
   {
      for(int  j=0;j<A[0].size();j++)
      {
          if(A[i][j]==0)
          {
             row[i]=0;
             col[j]=0;
          }
      }
   }
   
    for(int i=0;i<A.size();i++)
    {
      for(int  j=0;j<A[0].size();j++)
      {
         if(row[i]==0 || col[j]==0)
         {
            A[i][j]=0;
         }
      }
    }
}



----------------------------------------------------------------------------------------------------------------------------------------

//Optimal solution: TC = O(N*M)
                    //SC = O(1)

void Solution::setZeroes(vector<vector<int> > &A)
{
     int rowflag = 0;
     int colflag = 0;
 
     //To check if first row and first coloumn contains any zero.
     //Store if row and col have any 0 in them.
     for(int i=0;i<A.size();i++)
     {
         for(int j=0;j<A[0].size();j++)
         {
             if(i==0 && A[i][j]==0)
             {
                 rowflag = 1;
             }
             
             if(j==0 && A[i][j]==0)
             {
                 colflag = 1;
             }
         }
     }
     
     
     // Make use of first row and first coloumn as the dummy array 
     for(int i=0;i<A.size();i++)
     {
         for(int j=0;j<A[0].size();j++)
         {
             if(A[i][j]==0)
             {
                 A[0][j]=0;
                 A[i][0]=0;
             }
         }
     }
     
     //If any row or col has 0, make entire row and col as 0
     for(int i=1;i<A.size();i++)
     {
         for(int j=1;j<A[0].size();j++)
         {
             if(A[0][j]==0 || A[i][0]==0)
             {
                 A[i][j]=0;
             }
         }
     }
     
     // Make use of rowflag and colflag in which we stored the status of first row and first col
     for(int i=0;i<A.size();i++)
     {
         for(int j=0;j<A[0].size();j++)
         {
             if(rowflag == 1)
             {
                 A[0][j]=0;
             }
             if(colflag == 1)
             {
                 A[i][0]=0;
             }
         }
     }
     
}
