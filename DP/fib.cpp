#include<iostream>
using namespace std;

//Method 1

//  The naive/brute approach which takes nearly O(2^n) time complexity.

int fib(int n)
{
    if(n==0 || n==1)   //base case
    {
        return 1;
    }

    return fib(n-1) + fib(n-2);    // at every node e make 2 function calls

}

//Method 2

// We try to use Dynamic programming approach in recursive manner
int fib_rec(int n, int *arr)
{
    if(n==0 || n==1)   //base case
    {
        return 1;
    }

    if(arr[n]>0)
    {
            return arr[n];
    }

    int output = fib_rec(n-1,arr)+fib_rec(n-2,arr);
    arr[n] = output; // we store the computed value in the array(table) and it takes time complexity of O(n).

    return output;    
}


//Method 3

int fib_iter(int n)
{
   int *arr = new int[n+1];      //allocate a free space for new array
   arr[0]=1;
   arr[1]=1;

   for(int i=2;i<=n;i++)
   {
       arr[i]=arr[i-1]+arr[i-2];  //iteratively fill in the values from 2 to n (as value at '0' and '1' place is already 1 in case of fibbonacci numbers)
   }

   int output = arr[n];
   delete []arr;        //deallocate the array we created
   return output;



}




int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i]=0;
    }
    cout<<fib(n)<<endl;
    cout<<fib_rec(n,arr)<<endl;
    cout<<fib_iter(n)<<endl;
    return 0;
}