class Solution {
public:
    bool halvesAreAlike(string s) {

        int n = s.size();
        int freq = 0;

        for(int i=0;i<n;i++){
            
            s[i] = tolower(s[i]);

            if(i < n/2){
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                    freq++;
                }
            }else{
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                    freq--;
                }
            }
        }
        return (freq == 0);
    }
};
