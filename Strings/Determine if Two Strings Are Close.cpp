class Solution {
public:

   /*In this we dont need to perform any opertions.
   Just thing based on two operations what could be done with strings.
   Given operations are just to misguide us, they are senseless*/
    
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        /*If 2 words are of different sizes then we cannot say the strings are close*/
        if(n != m){
            return false;
        }

        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        /*Calculating the frequencies of both the words*/

        for(int i=0;i<n;i++){
            freq1[word1[i] - 'a']++;
        }

        for(int j=0;j<m;j++){
            freq2[word2[j] - 'a']++;
        }

        /*The set of characters should be same in both words, 
        they could differ in order and freqencies but if there 
        is any one charecter in word1 then it must also be a part of word2*/

        for(int i=0;i<26;i++){
            if(freq1[i] > 0 && freq2[i] == 0){
                return false;
            }
        }
        
        /*Also, the freqencies of the charecters should be same in both the words.*/

        sort(begin(freq1), end(freq1));
        sort(begin(freq2), end(freq2));

        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
};
