class Solution {
public:
    int fib(int n) {
        if(n == 0 || n==1){    //Base condition is always the smallest valid value of n
            return n;   
        }

        return fib(n-1)+fib(n-2);
    }
};