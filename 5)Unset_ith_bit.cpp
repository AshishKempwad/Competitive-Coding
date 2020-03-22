int turnOffIthBit(int n, int i)
{
  int X= (n & (1<<i));//Check if the i^th bit is 0 or not
  if(X) // if not 0 then make it 0
  {
      int z=(1<<i);
      z=n-z;
      return z;
  }
    else //if already zero dont do anything
    {
        return n;
    }
    
}
