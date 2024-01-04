class Solution {
public:
    string simplifyPath(string path) {
        //Beautiful Question

        int n = path.size();
        string res;
        stack<string>st;

        for(int i=0;i<n;i++){
            if(path[i] == '/'){
                continue;
            }

            string temp;

            while(i<n && path[i]!='/'){  //Words between two backslashes
               temp += path[i];
               i++;
            }

            if(temp == "."){  //If the word between 2 backslashes is ".", then ignore
            continue;
            }
            else if( temp == ".."){  //If it is ".." then we need to jump back one level
              if(!st.empty()){
                  st.pop();
              }
            }
            else{  //If it is any other thing, push it to stack
              st.push(temp);
            }
        }

        while(!st.empty()){
            res = "/" + st.top() + res; //Beautiful line of code [We take top of the stack and assign it to string and then pick the next one and assign to before that. Each word from stack is one directory/file and hence seperated by "/"]
            st.pop();
        }

        if(res.size() == 0){   //If nothing is present in the stack
            return "/";
        }

        return res;
    }
};
