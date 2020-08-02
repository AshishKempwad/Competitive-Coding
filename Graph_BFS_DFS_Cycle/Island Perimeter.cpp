class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int count=0;
        int internal=0;
         int rows = grid.size();
        int cols = grid[0].size();
    
        
        for(int i=0;i<rows;i++)
        {
           for(int j=0;j<cols;j++)
           {
               if(grid[i][j]==1)
               {
                   count++;
                   
                   if(i!=rows-1 && grid[i+1][j]==1)
                   {
                       internal++;
                   }
               
                   if(j!=cols-1 && grid[i][j+1]==1)
                   {
                       internal++;
                   }
    //               
               }
               
             
               
           }
        }
        
        int ans = (4 * count) - (2 * internal);
        
        return ans;
    }
};
