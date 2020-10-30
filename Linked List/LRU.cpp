/*Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists.
Otherwise, add the key-value pair to the cache.
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
Follow up:
Could you do get and put in O(1) time complexity?

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4


--------------------------------------------------------------------------------------------------------------------------------------------------------------------
Design Goals of Cache:

Latency - Is this problem very latency sensitive (Or in other words, Are requests with high latency and a failing request, equally bad?).
For example, search typeahead suggestions are useless if they take more than a second.

Consistency - Does this problem require tight consistency? Or is it okay if things are eventually consistent?

Availability - Does this problem require 100% availability?
There could be more goals depending on the problem.
It's possible that all parameters might be important, and some of them might conflict. 

In that case, you’d need to prioritize one over the other. 

Q: Is Latency a very important metric for us?
A: Yes. The whole point of caching is low latency.

Q: Consistency vs Availability?
A: Unavailability in a caching system means that the caching machine goes down,
which in turn means that we have a cache miss which leads to a high latency.
As said before, we are caching for a Twitter / Google like system.
When fetching a timeline for a user, I would be okay if I miss on a few tweets 
which were very recently posted as long as I eventually see them in reasonable time.
Unavailability could lead to latency spikes and increased 
load on DB. Choosing from consistency and availability, we should prioritize for availability.

Incache design, Availability >> Consistency

// DATA STRUCTURE USED : Map(unordered_map) and doubly linkedlist(list)

// IMP: At linkedlist level we dont store value, we just store the key.

----------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<list>

unordered_map<int,int>mp;
list<int>dq;
int cachesize = 0;

LRUCache::LRUCache(int capacity)  
{
    cachesize = capacity;
    mp.clear();
    dq.clear();
}

int LRUCache::get(int key)
{
    if(mp.find(key)==mp.end())   // if you dont find the key,return the -1
    {
        return -1;
    }
    else   //if key is present, then return corresponding value
    {
        set(key,mp[key]);  // before return, we reorder the list as its been accessed
        return mp[key];
    }
}

void LRUCache::set(int key, int value) 
{
    if(mp.find(key)==mp.end())   // if key isnt present, we add key and its value in the map
    {
        mp[key]=value;
        
        if(dq.size() < cachesize)   //if cache still has face, we add it in list
        {
            dq.push_back(key);   
        }
        else   //if cache is full, we need to remove the least recently used item and then
        {     // also remove that item from map and eventually create space in cache and add the item
            int ele_to_remove = dq.front();
            dq.pop_front();
            mp.erase(ele_to_remove);
            dq.push_back(key);
        }
    }
    else    // if key is already present, then could mean the value at that key is being updated. 
    {       //We need to reorder now, by removing it from wherever in between and adding it at the end
        mp[key]=value;   // as it was accessed
        dq.remove(key);
        dq.push_back(key);
    }

}
