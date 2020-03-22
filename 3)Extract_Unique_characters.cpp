#include<bits/stdc++.h>

char* uniqueChar(char *str)
{
  int len=strlen(str);
  if(len==0)
  {
      char *res=new char[1];
      res[0]='\0';
      return res;
  }
    
    char *res=new char[len+1];
    unordered_map<char,bool> hm;
    int i=0;
    for(int j=0;j<len;j++)
    {
        char currchar=str[j];
        if(hm.count(currchar)==0)
        {
            hm[currchar]=true;
            res[i++]=currchar;
        }
    }
    res[i]='\0';
    return res;
    
    

}

