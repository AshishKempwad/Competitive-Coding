bool check_in_circle(int i,int j,int no_of_circles,int radius,vector<int>&x_coordinates,vector<int>&y_coordinates)
{
    for(int k=0;k<no_of_circles;k++)
    {
        if( pow((i-x_coordinates[k]),2) + pow((j-y_coordinates[k]),2) <= pow(radius,2))
        {
            return true;  //You are touching/inside the circle
        }
    }
    
    return false;   // not inside/touching the circle and hence safe to move ahead
}

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

void dfs(int x,int y, vector<vector<bool>>&vis,int target_x,int target_y,int no_of_circles,int radius,vector<int>&x_coordinates,vector<int>&y_coordinates)
{
    vis[x][y]=true;
    
    for(int i=0;i<8;i++)
    {
        int newx = x+dx[i];
        int newy = y+dy[i];
        
        //We check 1)We are not out of bound 2)We havent visited this grid before 3)We are not touching/inside the circle
        if(newx >= 0 && newx <= target_x && newy >= 0 && newy <= target_y && vis[newx][newy]==false && !check_in_circle(newx,newy,no_of_circles,radius,x_coordinates,y_coordinates))
        {
            dfs(newx,newy,vis,target_x,target_y,no_of_circles,radius,x_coordinates,y_coordinates);   //Once we find we are safe, we move ahead
        }
    }
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F)
{
    
    vector<vector<bool>>vis(A+1,vector<bool>(B+1,false));//initialize the vis array
    
    //To check that we are not touching/inside the circle
    if(check_in_circle(0,0,C,D,E,F)==true)  //if we are inside the circle then, we fail as we enetered circle 
    {                                    // and hence invalid path. 
        return "NO";                     //If the distance between where we are standing and the centre of circle is less
    }                                    //than the radius, that means we are inside circle and hence we fail!!
    
    
    
    dfs(0,0,vis,A,B,C,D,E,F);
    
    if(vis[A][B]==true)
    {
        return "YES";
    }
    else
    {
       return "NO";
    }
   
}
