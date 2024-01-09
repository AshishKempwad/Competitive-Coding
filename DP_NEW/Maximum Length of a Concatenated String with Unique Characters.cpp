//Recursion
class Solution {
public:
    bool checkDuplicate(string &s1, string &s2){
        vector<int>freq(26,0);

        for(int i=0;i<s1.size();i++){
            /*Check for "aa","bb" conditions*/
            if(freq[s1[i]-'a'] > 0){
                return true;  //Has duplicates
            }
            freq[s1[i]-'a']++;
        }

        for(int i=0;i<s2.size();i++){
            if(freq[s2[i]-'a'] > 0){
                return true; //Has duplicates
            }
        }

        return false; //No duplicates
    }
    int solve(int idx, string temp, int n,vector<string>& arr){
        /*BASE CONDITION
        If we reach out of index, then return the length of temp 
        */
        if(idx >= n){
            return temp.size();
        }

        int include = 0;
        /*If there are no duplicates, then we can include it by concatenating.
         We can only include when there are no duplicates*/
        if(!checkDuplicate(arr[idx],temp)){
            string concatenatedString = temp + arr[idx];
            include = solve(idx+1,concatenatedString,n,arr);
        }
        /*We can exclude everytime*/
        int exclude = solve(idx+1,temp,n,arr);

        return max(include,exclude);

    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";
        return solve(0,temp,n,arr);
    }
};

//Recursion + Memo
class Solution {
public:
   
    unordered_map<string,int>mp;  //We are using map to memoize

    bool checkDuplicate(string &s1, string &s2){
        vector<int>freq(26,0);

        for(int i=0;i<s1.size();i++){
            /*Check for "aa","bb" conditions*/
            if(freq[s1[i]-'a'] > 0){
                return true;  //Has duplicates
            }
            freq[s1[i]-'a']++;
        }

        for(int i=0;i<s2.size();i++){
            if(freq[s2[i]-'a'] > 0){
                return true; //Has duplicates
            }
        }

        return false; //No duplicates
    }
    int solve(int idx, string temp, int n,vector<string>& arr){
        /*BASE CONDITION
        If we reach out of index, then return the length of temp 
        */
        if(idx >= n){
            return temp.size();
        }

        if(mp.find(temp) != mp.end()){
            return mp[temp];
        }

        int include = 0;
        /*If there are no duplicates, then we can include it by concatenating.
         We can only include when there are no duplicates*/
        if(!checkDuplicate(arr[idx],temp)){
            string concatenatedString = temp + arr[idx];
            include = solve(idx+1,concatenatedString,n,arr);
        }
        /*We can exclude everytime*/
        int exclude = solve(idx+1,temp,n,arr);

        return mp[temp] = max(include,exclude);

    }

    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp = "";
        return solve(0,temp,n,arr);
    }
};
