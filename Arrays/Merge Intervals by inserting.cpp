/*

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.

*/

//TC = O(nlogn)
//SC = O(n)

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
static bool compare(Interval n1,Interval n2)
{
    return n1.start < n2.start;
}
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval)
{
    
    if(intervals.empty())
    return {newInterval};
    
    intervals.push_back(newInterval);
    sort(intervals.begin(),intervals.end(),compare);
    vector<Interval>res;
    Interval curr = intervals[0];
    for(auto i=1;i<intervals.size();i++)
    {
        if(curr.end >= intervals[i].start)
        {
            curr.end = max(curr.end,intervals[i].end);
        }
        else
        {
            res.push_back(curr);
            curr = intervals[i];
        }
    }
    
    res.push_back(curr);
    
    return res;
  
}
