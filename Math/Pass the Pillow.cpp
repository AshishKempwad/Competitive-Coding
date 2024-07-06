class Solution {
public:
    int passThePillow(int n, int time) {
   /* Approach 1 : TC = O(n), SC = O(1)
   
        int pos = 1;
        bool flag = true;
        
        while(time--){
            if(flag){
                pos++;
                if(pos >= n){
                    flag = !flag;
                }
            }else{
                pos--;
                if(pos <= 1){
                    flag = !flag;
                }
            }
        }

        return pos;
        */

        /* Approach 2 : TC = O(1) SC = O(1)
          1. Base case : return time+1 if time < n - Observation
          2. Calculate full rounds(1 round = 1 movement rither left to right OR right to left)
          3. We need to compute no of passes/timeleft after complete rounds.
          4. If fullrounds%2 == 0 - this means we have travelled from right to left (opposite side). 
             And would now move from left to right (initial/original direction).
          5. Else we would have moved from left to right and now planning to move from right left. 
             Hence subtract it from n. (oppo direction)   
        */

        if(time < n){
            return time+1;
        }

        int fullRounds = time/(n-1);
        int timeLeft = time % (n-1);

        if(fullRounds%2 == 0){
            return timeLeft+1;
        }

        return n - timeLeft;
    
    }
};
