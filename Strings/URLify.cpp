#include <bits/stdc++.h>
using namespace std;

void urlify(string &s,int k)
{
    int i=0;
    int space_count=0;
    
    for(i=0;s[i];i++)
    {
        if(s[i]==' ')
        {
            space_count++;
        }
    }
    
    while(s[i-1]==' ')    //remove all the trailing spaces. Let one space be present at the end where we can add 'NULL' to signify that string has ended
    {
        space_count--;
        i--;
    }
    
    int new_length = i + space_count*2 + 1;  //as in place of space we have to put '%20'
    
    int index = new_length - 1;
    
    s[index]='\0';
    index--;
    
    for(int j=i-1;j>=0;j--)
    {
        if(s[j]==' ')
        {
            s[index]='0';
            s[index-1]='2';
            s[index-2]='%';
            index = index-3;
        }
        else
        {
            s[index]=s[j];
            index--;
        }
    }
    
    for(int i=0;i<new_length;i++)
      {
          cout<<s[i];
      }
    
}


int main() 
{

   int testcases;
   cin>>testcases;
   
   while(testcases--)
   {
       cin.ignore();
        string s;
        getline(cin,s);
       int k;
       cin>>k;
       
      urlify(s,k);
      cout<<endl;
   }
	return 0;
}
