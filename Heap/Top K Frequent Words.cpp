/*Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/

//TC = O(nlogk) we never have more than 'k' elements in heap, any given time.
//SC = O(n)  //Space used by map

class Solution {
    private:
    
    struct cmp
    {
        bool operator()(const pair<int,string>&a , const pair<int,string>&b)
        {
            if(a.first != b.first)   // if frequences are not same
            {
                return a.first > b.first;    //return the one having maximum frequncy
            }
            else  //If the frequences of the words are same then we return based on the dictionary order of the strings
            {
                return a.second < b.second;
            }
        }
    };
    
    
public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {
           unordered_map<string,int>mp;   // we use map to keep the count of frequency
          for(int i=0;i<words.size();i++)
          {
              mp[words[i]]++;
          }
        
         priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        
        for(auto &x : mp)
        {
            pq.push({x.second,x.first});   //push {frequncy,string}
            if(pq.size() > k)   //At any time we will have only 'k' elements in the minheap.
            {           
                pq.pop();      //We remove the least frequent words whenever the size of minheap exceeds 'k' 
            }
        }
        
        vector<string>res;
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(res.begin(),res.end());  // As it is minheap, the words would in descending order.
        return res;                      // i.e. The top element will be smaller than the element below it, hence we reverse the result before returning
        
    }
};

 
