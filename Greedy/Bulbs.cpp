/*N light bulbs are connected by a wire. Each bulb has a switch associated with it, however due to faulty wiring, a switch also changes the state of all the bulbs to the right of current bulb. Given an initial state of all bulbs, find the minimum number of switches you have to press to turn on all the bulbs. You can press the same switch multiple times.

Note : 0 represents the bulb is off and 1 represents the bulb is on.

Example:

Input : [0 1 0 1]
Return : 4

Explanation :

press switch 0 : [1 0 1 0]
press switch 1 : [1 1 0 1]
press switch 2 : [1 1 1 0]
press switch 3 : [1 1 1 1]

*/
    int Solution::bulbs(vector<int> &A) 
    {
        
        //When we press the switch on any bulb all the bulbs to the right og it toggle. 
        //ie. 1 becomes 0 & 0 becomes 1.
        
        //Find for first "0" then next find "1" and then "0" and so on.
        
        int bit = 0;
        //Just check 0 and 1 alternatively.
        int switches = 0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i] == bit%2)
            {
             switches++;
             bit++;
            }
        }
        
        return switches;
    }


