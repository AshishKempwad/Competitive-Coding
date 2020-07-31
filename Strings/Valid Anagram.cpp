class Solution {
public:
    bool isAnagram(string s, string t)
    {
        //Method 1 : TC = O(n)
        if(s.length() != t.length())
        {
            return 0;
        }
        int arr[256];
        memset(arr,0,sizeof(arr));
        
        for(int i=0;i<s.length();i++)
        {
            arr[s[i]]++;
            arr[t[i]]--;
        }
        
        for(int i=0;i<256;i++)
        {
            if(arr[i]!=0)
            {
                return 0;
            }
        }
        
        return 1;
        
        
        
        //Method 2 : TC = O(nlogn)
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int x=s.compare(t);
        if(x==0)
        {
            return true;
        }
        return false;
    }
};
