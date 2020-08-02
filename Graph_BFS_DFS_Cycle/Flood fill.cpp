class Solution {
public:
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    void DFS(vector<vector<int>>& image, int sr, int sc, int color,int newColor)
    {
        image[sr][sc]=newColor;
       for(int k=0;k<4;k++)
       {
           int x = sr+dx[k];
           int y = sc+dy[k];
           
           if(x >=0 && x<image.size() && y>=0 && y<image[0].size() && image[x][y]==color && image[x][y]!=newColor)
           {
              image[x][y]=newColor;  
               DFS(image,x,y,color,newColor);
           }
       }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
       if(image[sr][sc]==newColor)
       {
           return image;
       }
        
        DFS(image,sr,sc,image[sr][sc],newColor);
        return image;
    }
};
