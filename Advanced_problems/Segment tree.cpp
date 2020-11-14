#include <bits/stdc++.h>
#include<math.h>
using namespace std;

int arr[10000];   //We take some max size of input array
int seg[4*10000];   // Max length of segment tree is (4*n)


void build(int index,int low,int high)
{
    if(low==high)     //base condition of leaf nodes
    {
        seg[index]=arr[low];
        return;
    }
    
    int mid = (high+low)/2;   // we get the index
    build(2*index+1,low,mid);  // left node is 2*index+1
    build(2*index+2,mid+1,high);   // right node is 2*index+2
    seg[index] = seg[2*index+1]+seg[2*index+2];  // here we store the max in segment tree
    
}

int query(int index,int low,int high,int l,int r)
{
    //We could have three condition:
    //1) The node lies completely inside the range, return value
    //2) current node doesnt lie in the range, return INT_MIN(as we are dealing with finding max element)
    //3) node is partially in the range, move to both side and return max of the both sides
    
    if(low >= l && high <=r)  // inside the range
    {
        return seg[index];
    }
    if(high<l ||low>r)   //out of range
    {
        return INT_MIN;    
    }
    //if it lies partially,we move on both sides
    int mid = (low+high)/2;
    
    int left = query(2*index+1,low,mid,l,r);
    int right = query(2*index+2,mid+1,high,l,r);
    
    return max(left,right);
    
}

void pointupdate(int index,int low,int high,int node,int val)   // for single node value update
{
    if(low==high)
    {
        seg[low]=seg[low]+val;
    }
    else
    {
        int mid = (low+high)/2;
        if(node<=mid && node>=low)
        {
            pointupdate(2*index+1,low,mid,node,val);
        }
        else
        {
            pointupdate(2*index+2,mid+1,high,node,val);
        }
        
        seg[index]=seg[2*index+1]+seg[2*index+2];
    }
    // cout<<seg[index]<<endl;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    build(0,0,n-1);   // (start index,start of arr,end of arr)
    pointupdate(0,0,n-1,9,500);
    int q;
    cin>>q;    // no of queries
    while(q--)
    {
        int l,r;
        cin>>l>>r;   // range
        cout<<query(0,0,n-1,l,r)<<endl;   // (index,start,end,query range start,query range end)
    }
    
    
	return 0;
}
