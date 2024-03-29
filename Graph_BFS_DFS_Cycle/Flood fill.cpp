/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].

*/
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
-------------------------------------------------------------------------------------------------------

    class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int oldColor = image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=true;
        image[sr][sc]=color;

        vector<int>dx = {0,1,-1,0};
        vector<int>dy = {1,0,0,-1};

        while(!q.empty()){
            int sr = q.front().first;
            int sc = q.front().second;
             q.pop();

           for(int k=0;k<4;k++){
               int new_sr = sr + dx[k];
               int new_sc = sc + dy[k];
             
                if(new_sr >= 0 && new_sr < n && new_sc >=0 && new_sc < m && image[new_sr][new_sc]==oldColor && vis[new_sr][new_sc]==false){

                    vis[new_sr][new_sc]=true;
                    q.push({new_sr,new_sc});
                    image[new_sr][new_sc]=color;

                }
           }

        }

        return image;
        
    }
};
