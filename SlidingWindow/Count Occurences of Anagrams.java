class Solution {

    int search(String pat, String txt) {
        
        int patternLength = pat.length();
        int textLength = txt.length();
        int anagramCount = 0;
        
        if(patternLength > textLength){
            return 0;
        }
        
        int[] patternCountArray = new int[26];
        int[] textCountArray = new int[26];
        
        //Count the pattern freq
        for(char ch : pat.toCharArray()){
            patternCountArray[ch - 'a']++;
        }
        
        // Initialize the first window
        for(int i=0;i<patternLength;i++){  //windowSize = patternLength
            textCountArray[txt.charAt(i) - 'a']++;
        }
        
        if(Arrays.equals(patternCountArray, textCountArray)){
            anagramCount ++;
        }
        
        for(int i=patternLength;i<textLength;i++){
            textCountArray[txt.charAt(i) - 'a']++;
            textCountArray[txt.charAt(i - patternLength) - 'a']--;
            
            if(Arrays.equals(patternCountArray,textCountArray)){
                anagramCount++;
            }
        }
        
        return anagramCount;
        
 
    }
