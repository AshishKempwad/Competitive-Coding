bool isvalid(string s)
{
    if(s.size() > 3)
    {
        return false;
    }
    
    if(s.size() > 1 && s[0]=='0')
    {
        return false;
    }
    
    if(stoi(s) < 0 || stoi(s) > 255)
    {
        return false;
    }
    
    return true;
}

vector<string> Solution::restoreIpAddresses(string A)
{
    vector<string>res;
    int n = A.size();
    if(A.size() < 4  && A.size() > 12)
    {
        return {};
    }
    
    for(int i=1;i<4;i++)
    {
        string first = A.substr(0,i);  // substr(pos,len)
        if(isvalid(first))
        {
            for(int j=1; j<4 && i+j < n ; j++)
            {
                string second = A.substr(i,j);
                if(isvalid(second))
                {
                    for(int k=1; k<4 && i+j+k < n ; k++)
                    {
                        string third = A.substr(i+j,k);
                        string fourth = A.substr(i+j+k);
                        if(isvalid(third) && isvalid(fourth))
                        {
                            string current = first + "." + second + "." + third + "." + fourth;
                            res.push_back(current);
                        }
                    }

               }
            }
            
        }
    }
    
    return res;
}
