#include <bits/stdc++.h>
using namespace std;


int prec(char x)
{
    if(x == '^')
    {
        return 3;
    }
    if(x == '*' || x == '/')
    {
        return 2;
    }
    if(x == '+' || x == '-')
    {
        return 1;
    }
    
    return -1;
}




int main() 
{
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        string s;
        cin>>s;
       
        // getline(cin,s);
        //  cin.ignore();
        stack<char>st;
        string res="";
        for(int i=0;i<s.size();i++)
        {
            if( (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || s[i]==' ')  //It could a operand
            {
                res = res+s[i];
            }
            else if(s[i]=='(')    //It could be opening bracket
            {
                st.push(s[i]);
            }
            else if(s[i]==')')    //It could be closing bracket
            {
                while(!st.empty() && st.top()!='(')
                {
                    res = res+st.top();
                    st.pop();
                }
                
                if(st.top()=='(')
                {
                    st.pop();
                }
            }
            else             //It could a operator
            {
                while(!st.empty() && prec(s[i]) <= prec(st.top()) )
                {
                    res = res+st.top();
                    st.pop();
                }
                st.push(s[i]);
                
            }
        }
        
        while(!st.empty())
        {
            res = res+st.top();
            st.pop();
        }
        
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i];
        }
        
        cout<<endl;
    }
	
	return 0;
}
