class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
       
       //If event1 starts before event2 and event2 start before end of event1 OR
       //If event2 starts before event1 and event1 start before end of event2.    ---- There is a conflict
       if(event1[0] <= event2[0] && event2[0] <= event1[1] || 
          event2[0] <= event1[0] && event1[0] <= event2[1]){
            return true; //conflict
          }

          return false;


        // return (event1[0] <= event2[0] && event2[0] <= event1[1]||
        //         event2[0] <= event1[0] && event1[0] <= event2[1]);
    }
};
