//TC : O(n)
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int movement = 0;

        for(auto &log : logs){
            if(log == "../"){
                if(movement == 0){
                    continue;
                }
                movement++;
            }else if(log == "./"){
                continue;
            }else {
               movement--;
            }
        }

        return abs(movement);
    }
};
