class Solution {
    public boolean checkInclusion(String s1, String s2) {
        //s1 = Like pattern
        //s2 = Like text

        int patternLength = s1.length();
        int textLength = s2.length();

        if(patternLength > textLength){
            return false;
        }

        int[] patternCountArray = new int[26];
        int[] textCountArray = new int [26];

        for(int i=0;i<patternLength;i++){
            patternCountArray[s1.charAt(i) - 'a']++;
            textCountArray[s2.charAt(i) - 'a']++;
        }

        if(Arrays.equals(patternCountArray,textCountArray)){
            return true;
        }

        for(int i=patternLength;i<textLength;i++){
            textCountArray[s2.charAt(i) - 'a']++;
            textCountArray[s2.charAt(i - patternLength) - 'a']--;

            if(Arrays.equals(patternCountArray,textCountArray)){
                return true;
            }
        }

        return false;
    }
}
