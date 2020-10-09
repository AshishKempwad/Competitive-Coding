class Solution {
public:
    int jump(vector<int>& nums) 
    {
        //Tricky hard problem
        //Greedy approach
        
        int pos = 0;
        int destination = 0;
        int jump = 0;
        
        for(int i=0;i<nums.size()-1;i++)   // we dont need to consider the last jump.
        {
            destination = max(destination , i+nums[i]);
            if(i == pos)
            {
                jump++;
                pos = destination;
            }
            
        }
        
        return jump;
        
    }
};
