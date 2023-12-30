//Recursion
class Solution {
public:
    int climbStairs(int n) {
        if(n<0){
            return 0;   //If no stairs, no ways
        }
        if(n==0){
            return 1;  //We have got one way to cover all stairs
        }
        int one_step = climbStairs(n-1);
        int two_step = climbStairs(n-2);

        return one_step+two_step;
    }
};

//Recursion+Memo
class Solution {
public:
    int t[46]; //Maximum size given in constraint
    int solve(int n){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }

        if(t[n] != -1)
        {
            return t[n];
        }
        int one_step = solve(n-1);
        int two_step = solve(n-2);

        return t[n]=one_step+two_step;

    }
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};

//Bottom Up
class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1 || n==2){
            return n;
        }
        vector<int>t(n+1);
        t[0]=0;   //t[i] = no. of ways in which we can reach stairs "i"
        t[1]=1;
        t[2]=2;

        for(int i=3;i<=n;i++){
            t[i]=t[i-1]+t[i-2];
        }
        return t[n];
    }
};

//Constant Space
class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1 || n==2){
            return n;
        }
        int a=1;  //i-2
        int b=2;  //i-1
        int c=3;  //i

        for(int i=3;i<=n;i++){
            c=b+a;
            a=b;
            b=c;
        }
        return c;
    }
};

