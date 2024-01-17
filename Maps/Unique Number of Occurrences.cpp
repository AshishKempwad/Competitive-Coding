class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       /*We insert all the elements in unordered_map
       Then insert the freqencies of all elements into unordered_set.
       If the sizes of both are equal then its true as that means the freqencies are unique.
       LOGIC : If any of the freqencies of the elements are same, 
       then they will go as a single element in set and hence size differenece between map and set*/
        int n = arr.size();
        unordered_map<int,int>freq;
        unordered_set<int>s;

        for(auto &x : arr){
            freq[x]++;
        }

        for(auto &x : freq){
            s.insert(x.second);
        }

        return freq.size() == s.size();

    }
};
