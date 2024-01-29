//Recursion

class Solution {
public:
    bool solve(string s1, string s2){

        /*BASE CONDITION:
        If s1 and s2 and equal then we return true.
        If their lengths are different, then they can never be
         scrambled or same versions of each other as we could never reach or convert s1 to s2*/
        if(s1 == s2){
            return true;
        }

        if(s1.length() != s2.length()){
            return false;
        }

        int n = s1.length();

        //Return true if either of the case swapped or not_swapped matches/return true. 
        //Else we return false
        for(int i=1;i<n;i++){
            
            /*CASE I : SWAPPED
            eg : s1 = great  , s2 = eatgr
            Lets say we are swapping from index 2
            (i = 2)

            Just assume s1 is swapped from i=2, Hence there would be 2 parts
            Part1 = eat and part2=gr

            We need to hence compare "eat" from s1 with "eat" from s2.
            And similarly, "gr" from s1 with "gr" from s2.

            s1.substr(i,n-i) - "eat"     s2.substr(0,n-i) - "eat"

            s1.substr(0,i) - "gr"        s2.substr(n-i,i) - "gr"

            */

            bool swapped = solve(s1.substr(i,n-i), s2.substr(0,n-i)) &&
                        solve(s1.substr(0,i), s2.substr(n-i,i));

            if(swapped){
                return true;
            } 

             /*CASE II : NOT SWAPPED
            eg : s1 = great  , s2 = eatgr
            Lets say we are swapping from index 2
            (i = 2)

            Just assume s1 is not swapped from i=2, Hence there would be 2 parts
            Part1 = gr and part2=eat

            We need to hence compare "gr" from s1 with "ea" from s2.
            And similarly, "eat" from s1 with "tgr" from s2.

            s1.substr(0,i) - "gr"     s2.substr(0,i) - "ea"

            s1.substr(i, n-i) - "eat"        s2.substr(i,n-i) - "tgr"

            */

            bool notSwapped = solve(s1.substr(0,i), s2.substr(0,i)) &&
                            solve(s1.substr(i,n-1), s2.substr(i,n-1));

            if(notSwapped){
                return true;
            }           
        }    

        return false;                
    }
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};

//Recursion + Memo
class Solution {
public:

    unordered_map<string, bool> mp;

    bool solve(string s1, string s2){

        /*BASE CONDITION:
        If s1 and s2 and equal then we return true.
        If their lengths are different, then they can never be
         scrambled or same versions of each other as we could never reach or convert s1 to s2*/
        if(s1 == s2){
            return true;
        }

        if(s1.length() != s2.length()){
            return false;
        }

        string key = s1 + "_" + s2;

        if(mp.find(key) != mp.end()){
            return mp[key];
        }

        int n = s1.length();

        bool result = false;

        //Return true if either of the case swapped or not_swapped matches/return true. 
        //Else we return false
        for(int i=1;i<n;i++){
            
            /*CASE I : SWAPPED
            eg : s1 = great  , s2 = eatgr
            Lets say we are swapping from index 2
            (i = 2)

            Just assume s1 is swapped from i=2, Hence there would be 2 parts
            Part1 = eat and part2=gr

            We need to hence compare "eat" from s1 with "eat" from s2.
            And similarly, "gr" from s1 with "gr" from s2.

            s1.substr(i,n-i) - "eat"     s2.substr(0,n-i) - "eat"

            s1.substr(0,i) - "gr"        s2.substr(n-i,i) - "gr"

            */

            bool swapped = solve(s1.substr(i,n-i), s2.substr(0,n-i)) &&
                        solve(s1.substr(0,i), s2.substr(n-i,i));

            if(swapped == true){
                result = true;
                break;
            } 

             /*CASE II : NOT SWAPPED
            eg : s1 = great  , s2 = eatgr
            Lets say we are swapping from index 2
            (i = 2)

            Just assume s1 is not swapped from i=2, Hence there would be 2 parts
            Part1 = gr and part2=eat

            We need to hence compare "gr" from s1 with "ea" from s2.
            And similarly, "eat" from s1 with "tgr" from s2.

            s1.substr(0,i) - "gr"     s2.substr(0,i) - "ea"

            s1.substr(i, n-i) - "eat"        s2.substr(i,n-i) - "tgr"

            */

            bool notSwapped = solve(s1.substr(0,i), s2.substr(0,i)) &&
                            solve(s1.substr(i,n-i), s2.substr(i,n-i));

            if(notSwapped == true){
                result = true;
                break;
            }           
        }    

        return mp[key] = result;                
    }
    bool isScramble(string s1, string s2) {

        mp.clear();
        return solve(s1,s2);
    }
};
