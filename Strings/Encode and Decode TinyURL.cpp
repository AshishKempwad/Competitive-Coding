/*
Note: This is a companion problem to the System Design problem: Design TinyURL.
TinyURL is a URL shortening service where you enter a URL
such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

Design the encode and decode methods for the TinyURL service. 
There is no restriction on how your encode/decode algorithm should work.
You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
*/

class Solution {
public:

    string store = "0123456789acbdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string,string>cache;
    string prefix = "http://tinyurl.com/";
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
           string t = prefix;

          for(int i=0;i<6;i++)
          {
               t=t+store[rand()%(store.size()-1)];
          }
        
        cache[t] = longUrl;
        return t;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) 
    {
        return cache[shortUrl];    
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
