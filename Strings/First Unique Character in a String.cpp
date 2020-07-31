class Solution {
public:
    int firstUniqChar(string S)
    {
        //Method 1:
        //Efficient Method using array of 256 size
        
       int arr[256];
        memset(arr,0,sizeof(arr));

        int n = S.length();
        for(int i=0;i<n;i++)
        {
            arr[S[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            if(arr[S[i]] == 1)
            {
                return i;
            }
        }
    
    
    return -1;
        
        
        
        
    // Method 2 : Using Map
        
      unordered_map<char,int> mp;
        int n=s.size();
        for(auto &c : s)
        {
            mp[c]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(mp[s[i]]==1)
            {
                return i;
            }
        }
        return -1;
        
    }
};
