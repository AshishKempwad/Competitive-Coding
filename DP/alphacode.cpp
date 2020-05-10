#include<iostream>
using namespace std;

/* Question : Each number from 1-26 represent 'a' to 'z' respecively. Now 1123 may represent 'a(1)a(1)b(2)c(3)','k(11)b(2)c(3)','a(1)l(12)c(3)',etc.
Now given an array with the number we need to print number of such patterns possible for such an number.*/

// Method 1 [Brute method]

int num_code(int* arr,int size)
{
    if(size==0) //Return 1 for empty string
    {
        return 1;
    }
    if(size==1)  //Return 1 if the size is 1.
    {
        return 1;
    }
    int output = num_code(arr,size-1); //Find for first(size-1) numbers and then just add the last one.

    if((arr[size-2]*10 + arr[size-1]) <= 26 ) //Find for first(size-2) numbers and then add last numbers given that last two numbers combined are less than 26.
    {
       output += num_code(arr,size-2);
    }


return output;
}

//Method 2 [Dynamic Programming using recursive method]

/*Say the array is 1,1,1,1,1,..1 then we will have to consider all the combinations as every two combined will be less than 26. 
In such case its  better if we store the recursive(repeating substructures which could be used later.*/

int num_dp_r(int *arr,int size,int *temp)
{
   if(size==0 || size ==1)
   {
       return 1;
   }

   if(temp[size]>0)
   {
       return temp[size];
   }

   int output =  num_code(arr,size-1);
   if(arr[size-2]*10 + arr[size-1] <= 26)
   {
       output += num_code(arr,size-2);
   }

   temp[size]=output;
   return output;

}


//Method 3: DP with iteration

int num_dp_i(int *input,int size)
{
    int *output = new int[size+1];   //create a new array of length 'size+1'.
    output[0]=1; //as the number of different patterns with no number would 1(empty string)
    output[1]=1; //as the number of different patterns with 1 number would be 1.

    for(int i=2;i<=size;i++)
    {
        output[i] = output[i-1];
        if(input[i-2]*10 + input[i-1] <=26 )
        {
            output[i] += output[i-2];
        }
    }

    int ans = output[size];
    delete []output;
    return ans;
}





int main()
{
   int size;
   cin>>size;
   int arr[size];
   for(int i=0;i<size;i++)
   {
       cin>>arr[i];
   }
   int ans1=num_code(arr,size);
   cout<<ans1<<endl;

//    int temp[size] = {0}; //initialize it to zero
   int temp[size];
   for(int i=0;i<size;i++)
   {
       temp[i]=0;
   }
   int ans2 = num_dp_r(arr,size,temp);
   cout<<ans2<<endl;

   int ans3 =  num_dp_i(arr,size);
   cout<<ans3<<endl;

return 0;

}