class Solution {
public:
    int strStr(string s, string x) 
    {
        int length_of_pat=0;
        if( x.length()==0)
        {
            return 0;
        }
        if(x.length() > s.length())
        {
            return -1;
        }
        
        for(int i=0;i<(s.length()-x.length()+1);i++)
        {
            length_of_pat=0;
            for(int j=0;j<x.length();j++)
            {
                if(s[i+j]==x[j])
                {
                    length_of_pat++;
                }
                else
                {
                    break;
                }
                if(length_of_pat == x.length())
                {
                    return i;
                }
            }
        }

        return -1;
    }
};
