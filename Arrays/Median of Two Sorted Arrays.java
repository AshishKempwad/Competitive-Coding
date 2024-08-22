//Approach 1: 
//TC = O(m+n)log(m+n)

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;

        int[] merged = new int[n+m];
        int k=0;

        for(int i=0;i<n;i++){
            merged[k++] = nums1[i];
        }
        for(int j=0;j<m;j++){
            merged[k++] = nums2[j];
        }

        Arrays.sort(merged);

        int total = merged.length;

        if(total % 2 == 1){
            return (double) merged[total / 2];
        }else{
            int mid1 = merged[total/2 -1];
            int mid2 = merged[total/2];

            return ((double)mid1 + (double)mid2) / 2.0;
        }

    }
}



//Approach 2: 
//TC = O(m+n)

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;

        int i=0,j=0,m1=0,m2=0;

        for(int count=0;count<=(n+m)/2;count++){
           m2 = m1;

           if(i!=n && j!=m){
            if(nums1[i] > nums2[j]){
                m1 = nums2[j++];
            }else{
                m1 = nums1[i++];
            }
           }else if(i < n){
              m1 = nums1[i++];
           }else{
            m1 = nums2[j++];
           }
        }

        if((n+m) % 2 == 1){
            return (double) m1;
        }else{
            return ((double) m1 + (double) m2) / 2.0;
        }
    }
}


//Approach 3 : Optimized approach : Binary Search
//TC = log(m+n)

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int m = nums2.length;

        if(n > m){
            return findMedianSortedArrays(nums2,nums1);
        }

        int l = 0;
        int r = n;

        while(l <= r){

            //We will choose at max half elements at left side
            int Px = l + (r - l)/2;   // no of elements choosen from nums1
            int Py = (n+m+1)/2 - Px;   // no of elements we can choose from nums2.

            //Left side
            int x1 = (Px == 0) ? Integer.MIN_VALUE : nums1[Px-1];
            int x2 = (Py == 0) ? Integer.MIN_VALUE : nums2[Py-1];

            //Right Side

            int x3 = (Px == n) ? Integer.MAX_VALUE : nums1[Px];
            int x4 = (Py == m) ? Integer.MAX_VALUE : nums2[Py];


            if(x1 <= x4 && x2 <= x3){
                if((n+m)%2 == 1){
                    return Math.max(x1,x2);
                }else{
                    return (Math.max(x1,x2)+Math.min(x3,x4))/2.0;
                }
            }else if(x1 > x4){
                r = Px-1;
            }else{
                l = Px+1;
            }

        }

        return -1;
    }
}
