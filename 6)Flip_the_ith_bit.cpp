int flipIthBit(int n, int i)
{
  
  //We know we can flip the ith bit using bitwise xor as we know (X ^ 0 = X) and (X ^ 1 = ~X) and using this we can solve the problem of flipping ith bit.
  int z = (n ^ (1<<i);//(1<<i) means 2^i i.e we take all the other places as 0 and only ith bit as 1 and we know (X ^ 1 =~X),hence we get the flip of that bit.
  return z;
  
}
