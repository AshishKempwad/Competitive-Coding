int turnOffFirstSetBit(int n){
  if((n & 1)!=0) //if n is odd then just substract 1 from the number then you would make the lowest bit(1) as zero.
  {
      n=n-1;
      return n;
  }
    else//if the number n is even
    {
        for(int i=1;i<=n;i++)
        {
            if((n & i)!=0) // slowly increase the number i from 1 to n(as we are intrested in smallest bit as possible) amd we check for lowesr bit which is 1
            {
                n=n-i; //then substract that number from n(i.e. we make that lowest bit which is 1 as 0)
                return n;
            }
        }
    }
}


