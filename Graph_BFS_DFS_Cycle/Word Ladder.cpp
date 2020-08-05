/*

TEST CASE:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string>dict(wordList.begin(),wordList.end());  //put all the words from given wordlist in set
        
        if(dict.count(endWord)==0)
        {
            return 0;
        }
        queue<string>q;
        q.push(beginWord);
        
        int ladder = 1;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                string word = q.front();
                q.pop();
                if(word == endWord)
                {
                    return ladder;
                }
               
                
                for(int j=0;j<word.size();j++)
                {
                    char temp = word[j];
                    
                    for(char c ='a'; c<='z';c++)
                    {
                        word[j] = c;
                        
                        if(dict.count(word) != 0)   //if the transformed word is present in set, then push that to queue
                        {
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    
                    word[j]=temp;
                }
            }
            
            ladder++;
        }
        
       return 0; 
        
    }
};
