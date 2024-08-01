class Solution {
public:

    int minimumChairs(string s) {

        int chairs = 0;
        int minimumChairsRequired = 0;

        for(auto x : s){
            if(x == 'E'){
                chairs++;
            }else if(x == 'L'){
                chairs--;
            }
            minimumChairsRequired = max(minimumChairsRequired,chairs);
        }

        return minimumChairsRequired;
    }
};
