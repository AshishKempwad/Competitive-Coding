class Solution {
public:

    vector<int>getleftMaxArray(vector<int>&height,int n){
        vector<int>leftMax(n);
        leftMax[0]=height[0];
        for(int i=1;i<n;i++){
            leftMax[i] = max(leftMax[i-1],height[i]);
        }
        return leftMax;

    }

    vector<int>getrightMaxArray(vector<int>&height,int n){
        vector<int>rightMax(n);
        rightMax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i] = max(rightMax[i+1],height[i]);
        }
        return rightMax;
        
    }


    int trap(vector<int>& height) {
        int n = height.size();

        vector<int>leftMax = getleftMaxArray(height,n);
        vector<int>rightMax = getrightMaxArray(height,n);

        int totalWater=0;

        for(int i=0;i<n;i++){

            int h = min(leftMax[i],rightMax[i])-height[i];
            totalWater+=h; //As width is always 1
        }
        return totalWater;
    }
};
