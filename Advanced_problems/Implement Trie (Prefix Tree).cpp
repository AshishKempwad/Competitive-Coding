/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/


class TrieNode{
  public:
    vector<TrieNode*> dict;
    bool isEnd;
    TrieNode(){
        isEnd = false;
        dict.resize(26, nullptr);
    }
};

class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        int n = word.size();
        int index;
        TrieNode* curr = root;
        
        for(int i=0;i<n;i++)
        {
            index = word[i]-'a';
            if(curr->dict[index]==NULL)
            {
                curr->dict[index] = new TrieNode();
            }
            curr=curr->dict[index];
        }
        
        curr->isEnd=true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        int n=word.size();
        int index;
        TrieNode* curr=root;
        
        for(int i=0;i<n;i++)
        {
            index=word[i]-'a';
            curr=curr->dict[index];
            
            if(curr==NULL)
            {
                return false;   // word not found
            }
        }
        
        return curr->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        int n = prefix.size();
        int index;
        TrieNode* curr = root;
        
        for(int i=0;i<n;i++)
        {
            index = prefix[i]-'a';
            curr=curr->dict[index];
            if(curr==NULL)
            {
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
