/*
Given three non-collinear integral points in XY plane, find the number of integral points inside the triangle formed by the three points. 
(A point in XY plane is said to be integral/lattice point if both its co-ordinates are integral).

Approch:
We can use the Pick’s theorem, which states that the following equation holds true for a simple Polygon.
Pick's Theeorem:
 A = I + (B/2) -1

A ==> Area of Polygon
B ==> Number of integral points on edges of polygon
I ==> Number of integral points inside the polygon

Using the above formula, we can deduce,
I = (2A - B + 2) / 2 

We can find A (area of triangle) using below Shoelace formula.

A =  1/2 * abs(x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)) 

1. If the edge formed by joining V1 and V2 is parallel 
   to the X-axis, then the number of integral points 
   between the vertices is : 
        abs(V1.x - V2.x) - 1

2. Similarly, if edge is parallel to the Y-axis, then 
   the number of integral points in between is :
    abs(V1.y - V2.y) - 1

3. Else, we can find the integral points between the
   vertices using below formula:
     GCD(abs(V1.x-V2.x), abs(V1.y-V2.y)) - 1
   The above formula is a well known fact and can be 
   verified using simple geometry. (Hint: Shift the 
   edge such that one of the vertex lies at the Origin.) 

*/



#include <bits/stdc++.h>
using namespace std;


int gcd(int a,int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b , a%b);
}

int boundary(pair<int,int>p, pair<int,int>q)
{
    if(p.first == q.first)
    {
        return abs(p.second - q.second)-1;
    }
    else if(p.second == q.second)
    {
        return abs(p.first - q.first)-1;
    }
    else
    {
        return gcd(abs(p.first - q.first),abs(p.second - q.second))-1;
    }
}



int integral_points(pair<int,int>p,pair<int,int>q,pair<int,int>r)
{
    // Calculate Area of triangle using three points using shoelace formula
    
    int A = abs(p.first*(q.second - r.second) + q.first*(r.second - p.second) + r.first*(p.second - q.second));
    
    int boundary_points = boundary(p,q)+boundary(p,r)+boundary(q,r)+3;// we add three for three original vertices
    
    //Apply pick's theorem
    
    return (A - boundary_points + 2)/2;
}



int main()
{
    int testcases;
    cin>>testcases;
    
    while(testcases--)
    {
        pair<int,int>p;
        pair<int,int>q;
        pair<int,int>r;
        
        cin>>p.first;
        cin>>p.second;
        
        cin>>q.first;
        cin>>q.second;
        
        cin>>r.first;
        cin>>r.second;
        
        cout<<integral_points(p,q,r)<<endl;
        
        
    }
	
	return 0;
}
