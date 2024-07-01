class Trie {
public:
   
   struct trieNode{
     bool endOfWord;
     trieNode* children[26];
   };

    trieNode* root;

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->endOfWord = false;

        for(int i=0;i<26;i++){
            newNode->children[i] = NULL;
        }

        return newNode;
    } 

    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* crawler = root;

        for(int i=0;i<word.size();i++){
            if(crawler->children[word[i] - 'a'] == NULL){
                crawler->children[word[i]-'a'] = getNode();
            }
            crawler=crawler->children[word[i]-'a'];
        }

        crawler->endOfWord = true;
    }
    
    bool search(string word) {
        trieNode* crawler = root;

        for(int i=0;i<word.size();i++){

            if(crawler->children[word[i]-'a'] == NULL){
                return false;
            }
            crawler=crawler->children[word[i]-'a'];
        }
        if(crawler != NULL && crawler->endOfWord == true){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawler = root;

        int i;
        for(i=0;i<prefix.size();i++){

            int idx = prefix[i] - 'a';

             if(crawler->children[idx] == NULL){
                return false;
             }
             crawler=crawler->children[idx];
        }

        if(i == prefix.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
