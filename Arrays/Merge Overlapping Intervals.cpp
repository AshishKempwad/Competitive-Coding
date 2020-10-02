/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool compare(Interval &a, Interval &b)
{
    return a.start < b.start;
}
                                              
vector<Interval> Solution::merge(vector<Interval> &A)
{
    sort(A.begin(),A.end(),compare);
    int n = A.size();
    vector<Interval>res;
    Interval curr = A[0];
    
    for(int i=1;i<n;i++)
    {
        if(curr.end < A[i].start)
        {
            res.push_back(curr);
            curr = A[i];
        }
        else
        {
            curr.end = max(curr.end,A[i].end);
        }
    }
    res.push_back(curr);
    return res;
}

