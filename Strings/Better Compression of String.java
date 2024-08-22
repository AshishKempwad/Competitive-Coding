class Solution {
    public String betterCompression(String compressed) {
        int[] freq = new int[26];
        int n = compressed.length();

        for(int i=0;i<n;){
            char c = compressed.charAt(i++);
            int number = 0;

            while(i<n && compressed.charAt(i) >= '0' && compressed.charAt(i) <= '9'){
                number = number*10 + (compressed.charAt(i) - '0');
                i++;
            }
            freq[c - 'a'] += number;
        }

        StringBuilder sb = new StringBuilder();
        for(int i=0;i<26;i++){
            if(freq[i] != 0){
                sb.append((char)(i+'a')).append(freq[i]);
            }
        }

        return sb.toString();
    }
}
