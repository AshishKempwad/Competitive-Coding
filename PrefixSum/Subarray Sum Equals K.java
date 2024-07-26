class Solution {
    public int subarraySum(int[] nums, int k) {
      
        Map<Integer, Integer> mp = new HashMap<>();

        mp.put(0,1);

        int count = 0;
        int cumSum = 0;

        for(int i=0;i<nums.length;i++){
            
            cumSum += nums[i];

            if(mp.containsKey(cumSum-k)){
                 count += mp.get(cumSum-k);
            }

            mp.put(cumSum, mp.getOrDefault(cumSum,0)+1);
        }

        return count;


    }
}
