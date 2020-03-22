#include<bits/stdc++.h>
using namespace std;

int getChar(int i){
	return (char)(i+97);
}
void printPalindromicString(string s){
	map< char,vector<int> > Indexes;
	
	for(int i=0;i<s.length();i++){
		Indexes[s[i]].push_back(i);
	}
	
	int odd_count=0;
	int ans[s.length()];
	
	for(int i=0;i<26;i++){
		if(Indexes[getChar(i)].size() % 2 ==1){
			odd_count++;
		}
	}
	if(odd_count>1){
		cout<<"-1";
		return;
	}
	else{
		
		int start =0;
		int end = s.length()-1;
		
		for(int i=0;i<Indexes.size();i++){
			char cur_Char = getChar(i);
			for(int j=0;j<Indexes[cur_Char].size();j+=2){
				
				if((Indexes[cur_Char].size() - j )== 1){
					ans[s.length()/2]= Indexes[cur_Char][j];
					continue;
				}
				
				ans[start] = Indexes[cur_Char][j];
				ans[end] = Indexes[cur_Char][j+1];
				start++;
				end--;
			}
		}
	}
	
	for(int i=0;i<s.length();i++){
		cout<<ans[i]+1<<" ";
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		printPalindromicString(s);
		cout<<endl;
	}
}
