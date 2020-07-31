bool search(string pat, string txt) 
{ 
	int n = txt.length();
	int m = pat.length();
	int i=0;
	while(i<n)
	{
	    int j;
	    for(j=0;j<m;j++)
	    {
	        if(txt[i+j]!=pat[j])
	        {
	           break;
	        }
	    }
	    
	    if(j==m)
	    {
	        return 1;
	    }
	    if(j==0)
	    {
	        i++;
	    }
	    else
	    {
	        i=i+j;
	    }
	}
	
	return 0;
	// Your code here
	
} 
