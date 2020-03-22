int returnFirstSetBit(int n){
   if((n & 1) ==1)// check if number is even or odd and if it is odd then return 1 as the lowest bit of any odd number is 1. eg(3-01[1], 5-10[1], 9-100[1],...)
   {
       return 1;
   }
    else //if it is a even number
    {
        for(int i=1;i<=n;i++)
        {
            int z=(n & i );//we take bitwise and of given number with (1 to n) and the moment we find a value such that a (lowest number & n)!=0 we return that lowest number(because thats the smallest number with its bit as 1) 
            if(z!=0)
            {
                return z;
            }
            
        }
    }
}


