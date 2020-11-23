#include <bits/stdc++.h>
using namespace std;


class stacks{
    public:
    
	int cap;
	int top;
	int size;
	int *arr;


	stacks(int c)
	{
		cap=c;
		top=-1;

		// There is no need of an extra variable called size. We can simply calculate the size by doing top+1
		size=0;
		arr=new int[c];

	}

	void push(int x){
		if(size==cap)
			return;
		arr[++top]=x;
		size++;
	}

	void pop(){
		if(size==0)
			return;
		
		top--;
		size--;
		
	}

	int gettop(){
		if(size==0)
			return -1;
		return arr[top];

	}

	int getsize(){
		return size;
	}

	~stacks(){
		delete [] arr;
	}





};



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
      stacks st(n);
      for(int i=0;i<n;i++)
      {
          if(s[i]=='(' || s[i]=='[' || s[i]=='{')
          {
              st.push(s[i]);
          }
          else
          {
              if(st.getsize()==0)
              {
                  return 0;
              }
              else if(check(s[i],st.gettop())==false)
              {
                  return false;
              }
              else
              {
                  st.pop();
              }
          }
         
      }
        
        if(st.getsize()==0)
        {
            return true;
        }
        
        return false;
        
        
    }
};
