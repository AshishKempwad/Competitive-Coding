class Solution {
public:

    bool possibleToCompleteTrips(vector<int>& time, int totalTrips, long long mid){
        long long actualTrips = 0;

        for(auto &t : time){
            actualTrips += mid/t;
        }

        if(actualTrips >= totalTrips){
            return true;
        }

        return false;

    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long n = time.size();

        long long l = 1;
        long long h = (long long )*min_element(begin(time),end(time)) * totalTrips;
        long long res = -1;

        while(l<=h){
            long long mid = l + (h - l)/2;   //Mid is time to complete the trips

            if(possibleToCompleteTrips(time,totalTrips,mid)){
                res=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }

        }

        return res;
    }
};
