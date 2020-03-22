int turnOnIthBit(int n, int i)
{
   int X=(n & (1<< i)); // To check if i^th bit is 0 or 1
    
    if(X==0) //If the i^th bit is 0 make it 1 and add it to original n and return
    {
       int z=(1<<i);
       z=z+n;
       return z;
    }
    else // if i^th bit is already 1 you dont do anything just return it as it is
    {
        return n;
    }
    
}


