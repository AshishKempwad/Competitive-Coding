//TC : O(m*n)

class Solution {
    public int strStr(String haystack, String needle) {

        
        int haystackSize = haystack.length();
        int needleSize = needle.length();

        for(int i=0;i<=haystackSize-needleSize;i++){
            for(int j=0;j<needleSize;j++){
                if(haystack.charAt(i+j) != needle.charAt(j)){
                    break;
                }

                if(j == needleSize-1){
                    return i;
                }
            }
        }

        return -1;
    }
}

