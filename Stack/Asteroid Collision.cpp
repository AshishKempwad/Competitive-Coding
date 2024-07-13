class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        int n = asteroids.size();        
        vector<int>res;
        stack<int>st;

        for(int i=0;i<n;i++){
            if(asteroids[i] > 0){
                st.push(i);
            }else if(asteroids[i] < 0){
                while(!st.empty() && asteroids[i] != 0){
                    int top = st.top();
                    st.pop();

                    if(asteroids[top] > abs(asteroids[i])){
                        asteroids[i] = 0;
                        st.push(top);
                    }else if(asteroids[top] < abs(asteroids[i])){
                        asteroids[top] = 0;
                    }else{
                        asteroids[top] = 0;
                        asteroids[i] = 0;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            if(asteroids[i] != 0){
                res.push_back(asteroids[i]);
            }
        }

        return res;
    }
};
