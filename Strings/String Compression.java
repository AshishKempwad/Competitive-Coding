class Solution {
    public int compress(char[] chars) {
        int i=0;
        int j=0;
        int n = chars.length;

        while(j < n){
            int count = 0;
            char curr = chars[j];

            while(j < n && chars[j] == curr){
                j++;
                count++;
            }
            chars[i++] = curr;
            if(count > 1){
                for(char digit : Integer.toString(count).toCharArray()){
                    chars[i++] = digit;
                }
            }
        }

        return i;
    }
}
