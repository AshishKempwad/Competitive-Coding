   
    long n= A.size();
    
    long A_sum = 0;
    long  A_prod = 0;
    
    for(int i=0;i<n;i++)
    {
        A_sum+=A[i];
        A_prod = A_prod + (long)pow(A[i],2);   //IMP : Put (long) behind pow to take care of overflow condition
    }
    
    long n_sum = n*(n+1)/2;
    long n_prod = n*(n+1)*(2*n+1)/6;
    
    long eq1 = A_sum - n_sum;        //x-y
    long eq2 = A_prod - n_prod;     //x^2 - y^2
    
    long diff = eq1;
    
    long eq3 = eq2/eq1;    // (x^2 -y^2)/(x -y) == (x+y)

    
    long dup = (eq1 + eq3)/2;
    long miss = (eq1 - eq3)/(-2);
    
    return {(int)dup,(int)miss};
