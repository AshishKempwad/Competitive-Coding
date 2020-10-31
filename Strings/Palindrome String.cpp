/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/
int Solution::isPalindrome(string A) 
{
    // Ascii value of 'A' = 65 and that of 'a' = 92
    
    
    string s1="";
    for(auto x : A)
    {
        if( x >= 'a'  && x <= 'z')
        {
            s1+= x;
        }
        
        if(x >= 'A' && x <= 'Z')
        {
            s1+=(x+32);
        }
        if(x >= '0' && x <= '9')
        {
            s1+=x;
        }
    }
    
  int l=0;
  int r = s1.size()-1;
   
  while(r >= l)
  {
      if(A[l] != A[r])
      {
          return 0;
      }
       
      l++;
      r--;
  }
    
    return 1;
}
