#include<bits/stdc++.h>
using namespace std;
int main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    vector<string> v;
    map<string,int> mp;
    
     istringstream ss(s);
    do { 
        string word; 
        ss >> word;
        mp[word]++;

    } while (ss); 
    map<string,int> ::iterator it=mp.begin();
    
    while(it!=mp.end())
    {
        if(it->second >= 2)
        {
          cout<<it->first<<" "<<it->second<<endl;  
        }
    }
    
    
    
    
	return 0;
}

