class Solution {
public:

    void multiply(int multiplier,vector<int>&arr, int &size){
        int carry = 0;
        for(int i=0;i<size;i++){
            int res = multiplier * arr[i];
            res += carry;
            
            arr[i] = res%10;
            carry = res/10;
        }
        
        while(carry>0){
            arr[size] = carry%10;
            size++;
            carry = carry/10;
        }
    }
    vector<int> factorial(int N){
        // code here
        
        vector<int>arr(100000);
        arr[0] = 1;
        int size = 1;
        
        for(int multiplier=2;multiplier<=N;multiplier++){
            multiply(multiplier,arr,size);
        }
        vector<int>res;
        
        for(int i=size-1;i>=0;i--){
            res.push_back(arr[i]);
        }
        
        return res;
    }
};
