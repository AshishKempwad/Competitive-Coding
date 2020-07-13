class Solution {
public:
    
    bool check(char a,char b)
    {
        if((a==')' && b=='(') ||( a==']' && b=='[') || (a=='}' && b=='{'))
        {
            return true;
        }
        return false;
    }
   
    
    bool isValid(string s)
    {
      int n=s.size();  
      stack<char>st;
      for(int i=0;i<n;i++)
      {
          if(s[i]=='(' || s[i]=='[' || s[i]=='{')
          {
              st.push(s[i]);
          }
          else
          {
              if(st.empty())
              {
                  return 0;
              }
              else if(check(s[i],st.top())==false)
              {
                  return false;
              }
              else
              {
                  st.pop();
              }
          }
         
      }
        
        if(st.empty())
        {
            return true;
        }
        
        return false;
        
    }
};
