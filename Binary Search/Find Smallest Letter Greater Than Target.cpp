class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        //This problem is similar to finding ceil of the number problem

        int n = letters.size();
        int l = 0;
        int h=n-1;
        char res = letters[0]; //If there are no characters in letters that is lexicographically greater than target, we return first character in vector

        while(l<=h){
            int mid = l+(h-l)/2;
            if(letters[mid]==target){
                l=mid+1;
            }
            else if(letters[mid]<target){
                l=mid+1;
            }
            else{
                res = letters[mid];
                h=mid-1;
            }
        }
        return res;
    }
};
