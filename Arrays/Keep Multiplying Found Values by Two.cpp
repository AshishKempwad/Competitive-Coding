class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st;

        int multiplyValue = original;

        for(auto x : nums){
            st.insert(x);
        }

        while(st.count(multiplyValue)){
            multiplyValue = 2 * multiplyValue;
        }

        return multiplyValue;
    }
};
