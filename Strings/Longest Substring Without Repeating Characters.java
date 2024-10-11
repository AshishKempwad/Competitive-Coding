class Solution {
    public int lengthOfLongestSubstring(String s) {


        Map<Character,Integer>mp = new HashMap<>();
        int left = 0;
        int maxLen = 0;

        for(int right=0;right<s.length();right++){
            char ch = s.charAt(right);

            if(mp.containsKey(ch) && mp.get(ch) >= left){
                left = mp.get(ch)+1;
            }

            mp.put(ch,right);

            maxLen = Math.max(maxLen,right-left+1);

        }

        return maxLen;

    }
}
