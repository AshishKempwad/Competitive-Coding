Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively
i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on.


void rearrange(long long *arr, int n) 
{ 
	
	int min=0;
	int max = n-1;
	int i=0;
	int max_ele = arr[n-1]+1;
	while(i<n)
	{
	    if(i%2==0)
	    {
	       arr[i] = arr[i]+(arr[max]%max_ele)*max_ele;
	       i++;
	       max--;
	    }
	    else if(i%2==1)
	    {
	        arr[i] = arr[i]+(arr[min]%max_ele)*max_ele;
	        i++;
	        min++;
	    }
	}
	
	for(int i=0;i<n;i++)
	{
	    arr[i]=arr[i]/max_ele;
	}

	 
}
