class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int totalShifts = 0;
        int n = s.length();

        for(auto x : shift){
            if(x[0] == 0){
                totalShifts -= x[1];   //If moving towards left
            }else if(x[0] == 1){
                totalShifts += x[1];   //If moving towards right
            }
        }
       
        totalShifts = totalShifts % n; //We take mod, as if the no. of shifts is greater than the length if string then we only need to shift by reminder.

        if(totalShifts > 0){
            //right shift
            return s.substr(n-totalShifts)+s.substr(0,n-totalShifts);
        }else if(totalShifts < 0){
            //left shift
            totalShifts = -totalShifts;
            return s.substr(totalShifts)+s.substr(0,totalShifts);
        }

        return s; //when leftShift == rightShift



    }
};
