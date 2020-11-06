/*
Median is the middle value in an ordered integer list.
If the size of the list is even, there is no middle value. 
So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
*/


class MedianFinder {
public:
    /** initialize your data structure here. */
    
    priority_queue<int>maxheap;  
    priority_queue<int,vector<int>,greater<int>>minheap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num)
    {
          if(maxheap.empty() || maxheap.top() > num)
          {
              maxheap.push(num);
          }
          else
          {
                minheap.push(num);  
          }
        
        if(maxheap.size() > minheap.size()+1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        if(minheap.size() > maxheap.size()+1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
        
    }
    
    double findMedian() 
    {
        if(maxheap.size() == minheap.size())
        {
            double result = (maxheap.top()+minheap.top());
            result=result/2;
            return result;
        }
        else if(maxheap.size() > minheap.size())
        {
            return maxheap.top();
        }
        else
        {
            return minheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


/*

Structure : Max heap on left and min heap on right.
We take max element from maxheap,and min element from minheap
*/
