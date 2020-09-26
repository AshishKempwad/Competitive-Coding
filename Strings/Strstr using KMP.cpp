void computeLPS (string pattern, vector<int> &lps){
    int m = pattern.length();
    lps[0] = 0;
    int i =1, j=0;
    
    while(i< m){
        // If there's a repeated sub pattern mark it using the initial index where the pattern first occured!
        if(pattern[i]==pattern[j]){
            j++;
            lps[i] = j;
            i++;
        }
        // Else if its a new subpattern then check for the smaller repeated subpattern, else if it doesn't have a smaller subpattern, then initialise it to 0.
        else{
            if(j!=0) j = lps[j-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}



int Solution::strStr(const string hayStack, const string needle)
{
     int m = needle.length();
        int n = hayStack.length();
        
   // Taking care of corner cases!
        if(m==0 || n==0) return -1;
        if(m>n) return -1;
        
   //Initialising LPS
        vector<int>lps(m);
        
   //Preprocessing...
        computeLPS(needle,lps);
        
        int i = 0; // index for hayStack 
        int j = 0; // index for needle 
        while (i < n) {
            // If pattern matches
            if (needle[j] == hayStack[i])
            { 
                j++; 
                i++; 
            } 
            if (j == m) return i-j; // Pattern Found! We just need to return the nearest index!
            // mismatch after j matches 
            else if (i < n && needle[j] != hayStack[i]) 
            { 
                // Do not match lps[0..lps[j-1]] characters, 
                // they will match anyway 
                if (j != 0) 
                    j = lps[j - 1]; // See this that we are traversing only j back and i remains untouched!
                else
                    i = i + 1; 
            } 
        }
        // If pattern not found!
        return -1;

}
