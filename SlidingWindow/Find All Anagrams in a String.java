class Solution {
    public List<Integer> findAnagrams(String s, String p) {

        List<Integer> result = new ArrayList<>();
        int textLength = s.length();
        int patternLength = p.length();

        if(textLength < patternLength){
            return result;
        }

        int[] patternCountArray = new int[26];
        int[] textCountArray = new int[26];

        for(int i=0;i<patternLength;i++){
            patternCountArray[p.charAt(i) - 'a']++;
            textCountArray[s.charAt(i) - 'a']++;
        }

        if(Arrays.equals(patternCountArray, textCountArray)){
            result.add(0);
        }

        for(int i=patternLength;i<textLength;i++){
            textCountArray[s.charAt(i) - 'a']++;
            textCountArray[s.charAt(i - patternLength) - 'a']--;

            if(Arrays.equals(patternCountArray, textCountArray)){
                result.add(i - patternLength + 1);
            }
        }

        return result;

    }
}
