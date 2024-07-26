class Solution {
    public int findMaxLength(int[] nums) {

        //We will treat 0 as -1 for solving the problem
        Map<Integer,Integer>mp = new HashMap<>();
        mp.put(0,-1);   //For base condition we say we have seen 0 at index -1

        int maxLength = 0;
        int cumSum = 0;

        for(int i=0;i<nums.length;i++){

            cumSum += (nums[i] == 1 ? 1 : -1); // we treat 0 as -1 and 1 as 1 itself. As 1 and -1 cancel each other

            if(mp.containsKey(cumSum)){
                maxLength = Math.max(maxLength, i - mp.get(cumSum));
            }else{
                  mp.put(cumSum,i);
            }     
        }

        return maxLength;
    }
}
