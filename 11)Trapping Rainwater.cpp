int trappingWater(int arr[], int n){

  int a[n]={0};
  int b[n]={0};
  int total = 0;
  int final[n];
  
int max=arr[0];
int end_max=arr[n-1];

for(int i=0;i<n;i++)
{
    if(max>=arr[i])
    {
        a[i]=max;
        max=a[i];
    }
    else
    {
        a[i]=arr[i];
        max=a[i];
    }
}

for(int j=n-1;j>=0;j--)
{
    if(end_max >= arr[j])
    {
        b[j]=end_max;
        end_max=b[j];
    }
    else
    {
        b[j]=arr[j];
        end_max=b[j];
    }
}

for(int k=0;k<n;k++)
{
    if(a[k]>=b[k])
    {
        final[k]=b[k]-arr[k];
        total=total+final[k];
    }
    else
    {
        final[k]=a[k]-arr[k];
        total=total+final[k];
    }
}

return total;
  
    // Your code here
    
}
