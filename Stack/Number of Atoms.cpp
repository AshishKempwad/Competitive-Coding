class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<unordered_map<string,int>>st;
        st.push(unordered_map<string,int>());
        int i=0;

        while(i<n){
            if(formula[i] == '('){
                /* 1. Insert a new map in the stack
                */

                st.push(unordered_map<string,int>());
                i++;

            }else if(formula[i] == ')'){
                /* 1. Pop the content from top of stack
                   2. Check the digit after closing bracket and multiply all the elements with that.
                   3. Merge the popped elements with top of stack
                */
                i++;
                unordered_map<string,int> currMap = st.top();
                st.pop();

                string multiplierString;
                while(i<n && isdigit(formula[i])){
                    multiplierString.push_back(formula[i]);
                    i++;
                }

                int multipleirInteger = multiplierString.empty() ? 1 : stoi(multiplierString);

                for(auto &it : currMap){
                    string element = it.first;
                    int count = it.second;

                    currMap[element] = count * multipleirInteger;
                }

                for(auto &it : currMap){
                    string element = it.first;
                    int count = it.second;

                    st.top()[element] += count;
                }

            }else{
                /* 1. Coming in this else part means you have encountered alphabet 
                   2. There could elements like 'He' or 'Mg' hence we need to check for next alphabet as well which should be in lower
                   3. Then we take the count of digits which are following the alphabet and add that to top of stack.
                   4. If there is no digit, that means its count is 1. Hence we add 1
                */

                string currElement;
                currElement.push_back(formula[i]);
                i++;

                while(i<n && isalpha(formula[i]) && islower(formula[i])){
                    currElement.push_back(formula[i]);
                    i++;
                }

                string currCountInString;

                while(i<n && isdigit(formula[i])){
                    currCountInString.push_back(formula[i]);
                    i++;
                }

                int currCountInInteger = currCountInString.empty() ? 1 : stoi(currCountInString);

                st.top()[currElement] += currCountInInteger;

            }
        }

       /* 1. We need to return the result in sorted order, hence we put the contents from unordered_map to ordered_map(i.e map).
          2. If the count is greater than 1, then only we mention that in result else return that directly.
       */
        map<string,int>sortedMap(begin(st.top()),end(st.top()));
        string res;

        for(auto &it : sortedMap){
           res += it.first;

           if(it.second > 1){
             res += to_string(it.second);
           }

        }

        return res;
    }
};
