


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


