class Solution {
public:
                                         ///APPROACH 1///
                                        
   /* TC = O(2^2n * 2n) - 2^2n -> For backtracking and recursion. for every position we have 2 choices. 
                                  And total positions = 2*n (n = opening bracket and n closing bracket).
                        - 2n  -> For checking if the string is Valid or not using stack.

       SC = O(2n * 2n) - 2n -> For recursion tree
                       - 2n -> Extra space used for stack

   */

   vector<string>res;

   bool isValidString(string &currentString){
      stack<char>st;
      int n = currentString.length();

      for(int i=0;i<n;i++){
        if(currentString[i] == '('){
            st.push(currentString[i]);
        }else if(!st.empty()){   //Important : First check stack is not empty before accessing it to check the top element
            if(currentString[i] == ')' && st.top() == '(' ){
               st.pop();
            }
        }else{
            st.push(currentString[i]);
        }
      }

      if(st.size() == 0){
        return true;
      }
      return false;

      /* Much better way for validating the string in constant space without using any stack. SC = O(1)
         int count = 0;

         for(auto &ch : currentString){
            if( ch == '(' ){
                count++;
            }else if(ch == ')' ){
                count--;

                if(count < 0){    // We add this check to ensure that ")()(" are marked as true. If at any given point of time count < 0 - return false
                    return false;
                }
            }
         }

         return count=0;  //If count=0 - return true else return false;
      */
   }

   void solve(int n, string &currentString){

        if(currentString.length() == 2*n){
            if(isValidString(currentString) == true){
                res.push_back(currentString);
            }
             return;
        }

        currentString.push_back('('); //Do Something
        solve(n,currentString);     //Explore
        currentString.pop_back();  //BackTrack
  
        currentString.push_back(')'); // Do Something
        solve(n,currentString);      //Explore
        currentString.pop_back();  //BackTrack

   }

    vector<string> generateParenthesis(int n) {
        string currentString = "";
        solve(n,currentString);
        return res;
    }
                                  /////////////////// APPROACH 2/////////////

     /* Same code - minor modification. We wont need to check if the string is valid by doing minor changes
        1. For any given string of length n - It would 2*n length paranthesis. [n - opening + n - closing]
        2. Dont call further recusrion of either opening or closing bracket is more than "n".
           And no. of closing bracket should always be less than or equal to opening bracket in current instance. 
           As we cannot have closing bracket before opening bracket.



    vector<string>res;
    void solve(int n, string &currentString, int opening, int closing){

        if(currentString.length() == 2*n){
            res.push_back(currentString);
            return;
        }
       
        if(opening < n){
            currentString.push_back('('); //Do Something
            solve(n,currentString,opening+1,closing);     //Explore
            currentString.pop_back();  //BackTrack
        }
        if(closing < opening)
        currentString.push_back(')'); // Do Something
        solve(n,currentString,opening,closing+1);      //Explore
        currentString.pop_back();  //BackTrack

   }   

    vector<string> generateParenthesis(int n) {
            string currentString = "";
            solve(n,currentString,0,0);
            return res;
    }


     */                             
    
};
