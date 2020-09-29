//Method 1:


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        string s1;
        cin>>s1;
        
        string s2;
        cin>>s2;
        
        if(s1.size() != s2.size())
        {
            cout<<"0";
        }
        else
        {
            bool check = false;
            string temp="";
            for(int i=0;i<s2.size();i++)//clockwise direction
            {
                temp = temp + s2[(i+2)%s2.size()];
            }
            
            if(temp == s1)
            {
                cout<<"1";
                check = true;
            }
            
            if(check == false)
            {
                temp="";
                
                for(int i=0;i<s2.size();i++)//anticlo
                {
                    temp = temp + s2[(i+s2.size()-2)%s2.size()];
                }
                
                if(temp == s1)
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
                }
            }
         
        }
        
        cout<<endl;
    }
	//code
	return 0;
}




//Method 2: 


bool isRotated(string str1, string str2) 
{ 
    if (str1.length() != str2.length()) 
        return false; 
  
    string clock_rot = ""; 
    string anticlock_rot = ""; 
    int len = str2.length(); 
  
    // Initialize string as anti-clockwise rotation 
    anticlock_rot = anticlock_rot + 
                    str2.substr(len-2, 2) + 
                    str2.substr(0, len-2) ; 
  
    // Initialize string as clock wise rotation 
    clock_rot = clock_rot + 
                str2.substr(2) + 
                str2.substr(0, 2) ; 
  
    // check if any of them is equal to string1 
    return (str1.compare(clock_rot) == 0 || 
            str1.compare(anticlock_rot) == 0); 
} 
