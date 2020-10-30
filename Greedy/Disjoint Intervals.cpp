/*
Given a set of N intervals denoted by 2D array A of size N x 2,
the task is to find the length of maximal set of mutually disjoint intervals.
Two intervals [x, y] & [p, q] are said to be disjoint if they do not have any point in common.
Return a integer denoting the length of maximal set of mutually disjoint intervals.

Problem Constraints
1 <= N <= 105
1 <= A[i][0] <= A[i][1] <= 109

Input Format
First and only argument is a 2D array A of size N x 2 denoting the N intervals.

Output Format
Return a integer denoting the length of maximal set of mutually disjoint intervals.

Example Input
Input 1:
 A = [
       [1, 4]
       [2, 3]
       [4, 6]
       [8, 9]
     ]
Input 2:
 A = [
       [1, 9]
       [2, 3]
       [5, 7]
     ]
     
Example Output
Output 1:
 3
Output 2:
 2

Example Explanation
Explanation 1:

 Intervals: [ [1, 4], [2, 3], [4, 6], [8, 9] ]
 Intervals [2, 3] and [1, 4] overlap.
 We must include [2, 3] because if [1, 4] is included thenwe cannot include [4, 6].
 We can include at max three disjoint intervals: [[2, 3], [4, 6], [8, 9]]


*/
bool cmp(const vector<int>&A,const vector<int>&B)  //sorting based on the end time
{
   return A[1] < B[1];
}

int Solution::solve(vector<vector<int> > &A)
{
    sort(A.begin(),A.end(),cmp);  //we sort based on the ending time of the interval
    int count=1;
   int endtime = A[0][1];
    for(int i = 1 ; i < A.size() ; i++)
    {
        if(A[i][0] > endtime)   //if start time of next interval is greater than end time of current interval then we increment that as that would be a disjoint set
        {
          count++;
          endtime = A[i][1];  //update new endtime
        }
    }
    return count;
    
}
