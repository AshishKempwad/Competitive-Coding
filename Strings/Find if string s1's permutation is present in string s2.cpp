class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int>goal(26);
        vector<int>curr(26);
        
        for(int i=0;i<s1.size();i++)
        {
            goal[s1[i] - 'a']++;
        }
        
        for(int i=0;i<s2.size();i++)
        {
            curr[s2[i]-'a']++;
            
            if(i >= s1.size())
            {
                curr[s2[i-s1.size()] - 'a']--;
            }
            
            if(goal == curr)     ///IN c++ we can directly check if two vectors are same or not
            {
                return true;
            }
        }
        return false;
    }
};
