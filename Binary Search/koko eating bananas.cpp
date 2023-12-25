class Solution {
public:
    
    int speed_of_eating(int speed,vector<int>& piles)
    {
        int Time=0;
        
        for(int i=0;i<piles.size();i++)
        {
            Time=Time+ceil(piles[i]/(double)speed);
        }
        return Time;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int H)
    {
        int n=piles.size();
        int l=1;
        int h=INT_MIN;
        for(int i=0;i<n;i++)
        {
            h=max(h,piles[i]);
        }
        int speed=0;
        
        int eating_speed=0;
        while(l<=h)
        {
            int mid = (l+h)/2;
            eating_speed = speed_of_eating(mid,piles);
            if(eating_speed==H)
            {
                return mid;
            }
            else if(eating_speed>H)
            {
                l=mid+1;
            }
            else if(eating_speed<H)
            {
                h=mid-1;
            }
        }
       
        return l;
    }
};
-------------------------------------------------------------------------
//Same Approach - Different method
    class Solution {
public:

    bool canEatAll(vector<int>& piles, int mid, int hours){
        long long int actualHours = 0;

        for(auto &x : piles){
          actualHours += x/mid;

          if(x%mid!=0){   //If any remaining bananas then 1 more hr to eat them
              actualHours++;
          }
        }

        if(actualHours <= hours){
            return true;
        }
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int hours) {
        int n = piles.size();
        int l = 1;
        int h = *max_element(begin(piles),end(piles)); // Maximum koko can eat in 1 hr
        int res = -1;

        while(l<=h){
            int mid = l + (h - l)/2;   //Per hour I can eat mid no of bananas

            if(canEatAll(piles,mid,hours)){
                res=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return res;
    }
};
