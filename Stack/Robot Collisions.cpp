class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int>actualIndex(n);

        for(int i=0;i<n;i++){
            actualIndex[i] = i;
        }

       
        auto cmp = [&](int &i, int &j){     
            return positions[i] < positions[j];
        };
        
        //Sort the Robot vector/list based on the position in ascending order.
        sort(begin(actualIndex),end(actualIndex),cmp);

        vector<int>res;
        stack<int>st;

        for(auto &currIndex : actualIndex){
            //If the robots are moving towards Right, we store them in stack
            if(directions[currIndex] == 'R'){
                st.push(currIndex);
            }else{
                //It means we have encountered the robot moving towards left
                while(!st.empty() && healths[currIndex] > 0){
                    int top = st.top();
                    st.pop();
                    
                    if(healths[currIndex] < healths[top]){
                        healths[top] = healths[top] - 1;
                        healths[currIndex] = 0;
                        st.push(top);
                    }else if(healths[currIndex] > healths[top]){
                        healths[top] = 0;
                        healths[currIndex] = healths[currIndex] - 1;
                    }else{
                        healths[currIndex] = 0;
                        healths[top] = 0;
                    }
                }
            }
        }

       for(int i=0;i<n;i++){
        if(healths[i] > 0){
            res.push_back(healths[i]);
        }
       }

        return res;
    }
};
