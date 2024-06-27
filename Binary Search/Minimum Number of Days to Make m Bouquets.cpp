class Solution {
public:

    int makeBouqets(int mid,vector<int>& bloomDay, int k){
        int noOfBouqets = 0;
        int adjacentBloomedflowers = 0;

        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= mid){
                adjacentBloomedflowers++;
            }else{
                adjacentBloomedflowers = 0;
            }
            if(adjacentBloomedflowers == k){
                noOfBouqets++;
                adjacentBloomedflowers = 0;
            }
        }

        return noOfBouqets;
    }
   
    int minDays(vector<int>& bloomDay, int m, int k) {
        //Binary Search on answer pattern
        int startDate = 0;
        int endDate = *max_element(begin(bloomDay),end(bloomDay));
        int minDays = -1;

        while(startDate <= endDate){
            int mid = startDate + (endDate - startDate)/2;

            if(makeBouqets(mid,bloomDay,k) >= m){
                minDays = mid;
                endDate = mid-1;
            }else{
                startDate = mid+1;
            }
        }

        return minDays;
    }
};

/*
    We apply binary search on answer pattern here.
    1)startDate would be 0 and endDate would be max Day in given array
    2)Apply Binary Search
    3)Check if we can make "m" bouqets and based on that shift startDate or endDate (i.e. left or right for binary search)
    4) In "makeBouqets" method check the no of bouqets we can make by using "adjacent" flowers. 
*/
