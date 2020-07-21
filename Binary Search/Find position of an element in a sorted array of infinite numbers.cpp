int binary_search(int arr[],int l,int h,int x)
{
   while(l<=h)
   {
     int mid = l + (h-l)/2;
     if(arr[mid] == x)
     { 
       return mid;
     }
     else if(x > arr[mid])
     {
       l = mid+1;
     }
     else if(x < arr[mid])
     {
       h = mid-1;
     }

   }
   
   return -1;

}





int binary_search_modified(int arr[],int x)
{
   int low = 0;
   int high = 1;
   
   while(x > arr[high])
   {
      low = high;
      high = high * 2;
   }
   cout<<binary_search(arr,l,h,x);
}
