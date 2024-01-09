class Solution {
public:
    int nthUglyNumber(int n) {

        /*arr[n] contains nth ugly number
        We dont staire anything at arr[0].
        We start storing from arr[1]=1
        */
        vector<int>arr(n+1);

        int i2,i3,i5;
        i2=i3=i5=1;   //Initially all are 1

        arr[1]=1;

        for(int i=2;i<=n;i++){
            int i2UglyNum = arr[i2]*2;
            int i3UglyNum = arr[i3]*3;
            int i5UglyNum = arr[i5]*5;

            int minUglyNum = min({i2UglyNum,i3UglyNum,i5UglyNum});   //Check for minimum
            arr[i] = minUglyNum;

            /*To remove all the elements which have been stored in the arr already
               6 = 3*2 and also 6 = 2*3. Hence we need to remove 6 from both i2 and i3. Hence we increment them after storing in array*/
            if(minUglyNum == i2UglyNum){
                i2++;
            }
            if(minUglyNum ==i3UglyNum){
                i3++;
            }
            if(minUglyNum == i5UglyNum){
                i5++;
            }
        }

        return arr[n];
    }
};
