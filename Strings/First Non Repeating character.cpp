// Complete this function
char nonrepeatingCharacter(string S)
{
    int arr[256];
    memset(arr,0,sizeof(arr));
    
    int n = S.length();
    for(int i=0;i<n;i++)
    {
        arr[S[i]]++;
    }
    
    for(int i=0;i<n;i++)
    {
        if(arr[S[i]] == 1)
        {
            return S[i];
        }
    }
    
    
    return '$';
   //Your code here
   
}
