class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

      /*Approach 1*/
      //TC = O(n) SC = O(n)

        int n = nums1.size();
        int m = nums2.size();
        vector<int>res;

        // unordered_map<int,int>mp;
      
        // for(int i=0;i<n;i++){
        //     mp[nums1[i]]++;
        // }

        // for(int i=0;i<m;i++){
        //     if(mp[nums2[i]] > 0){
        //        res.push_back(nums2[i]);
        //        mp[nums2[i]]--;
        //     }
        // }

        // return res;

        /*Approach 2*/
        //TC = O(nlogn) SC = O(1)

        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));

        int i=0;
        int j=0;

        while(i < n && j < m){
            if(nums1[i] > nums2[j]){
                j++;
            }else if(nums1[i] < nums2[j]){
                i++;
            }else{
                res.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        return res;


  
    }
};
