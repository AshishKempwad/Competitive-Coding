class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //Approach 1. - TC = O(n+m) SC = O(m+n)
        

      /*  unordered_set<int>st1(begin(nums1),end(nums1));
        
        unordered_set<int>st2;

        for(int i=0;i<nums2.size();i++){
            if(st1.find(nums2[i]) != st1.end()){
                st2.insert(nums2[i]);
            }
        }

        vector<int>res(begin(st2),end(st2));
        return res; */

        //Approach 2 TC = O(m+n) Sc = O(n)

        /*unordered_set<int>st(begin(nums1),end(nums1));
        vector<int>res;

        for(int i=0;i<nums2.size();i++){
            if(st.find(nums2[i]) != st.end()){
                res.push_back(nums2[i]);
                st.erase(nums2[i]);
            }
        }

        return res;*/

        //Approach 3 TC = O(nlogn+mlogn) SC = (1)

        int n = nums1.size();
        int m = nums2.size();
        vector<int>res;

        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));

        int i=0;
        int j=0;

        while(i < n && j < m){
            if(nums1[i] < nums2[j]){
                i++;
            }else if(nums1[i] >  nums2[j]){
                j++;
            }else{
                res.push_back(nums1[i]);
                
                while(i+1 < n && nums1[i] == nums1[i+1]){
                    i++;
                }
                while(j+1 < m && nums2[j] == nums2[j+1]){
                    j++;
                }
                i++;
                j++;
            }
        }

        return res;

    }
};
