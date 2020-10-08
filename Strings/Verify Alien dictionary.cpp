class Solution {
public:
    
    int compare(string s1, string s2,vector<int>&arr)
    {
        int i=0;
        int j=0;
        int char_compare=0;
        
        while( i<s1.length() && j<s2.length() && char_compare==0)
        {
            
            char_compare = arr[s1[i] - 'a'] - arr[s2[j] - 'a']; //first word should be smaller lexographically 
            j++;
            i++;
        }
        
        if(char_compare==0)
        {
            return s1.length() - s2.length();      // If one of the word is smaller than the other then return the                                                      //length. eg: In case of ['hel','hello'], 'hel' must come before 'hello'.
        }
       return char_compare;
        
    }
    
    
    bool isAlienSorted(vector<string>& words, string order) 
    {
        vector<int>arr(26);
        for(int i=0;i<order.length();i++)
        {
            arr[order[i]-'a']=i;        //we store their words in lexographical order
        }
        
        for(int i=1;i<words.size();i++)
        {
            if(compare(words[i-1],words[i],arr) > 0)
            {
                return false;
            }
        }
        
        return true;
        
    }
};
