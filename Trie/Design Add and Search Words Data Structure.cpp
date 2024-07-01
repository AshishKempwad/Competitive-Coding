class WordDictionary {
public:

    struct trieNode{
        bool endOfWord;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->endOfWord = false;

        for(int i=0;i<26;i++){
            newNode->children[i] = NULL;
        }

        return newNode;
    }

    trieNode* root;

    WordDictionary() {
        root = getNode();
    }
 
    void addWord(string word) {
        trieNode* crawler = root;

        for(int i=0;i<word.size();i++){
            if(crawler->children[word[i] - 'a'] == NULL){
                crawler->children[word[i]-'a'] = getNode();
            }
            crawler=crawler->children[word[i]-'a'];
        }

        crawler->endOfWord = true;
    }
    
    bool searchUtil(trieNode* root, string word){

        trieNode* crawler = root;

        for(int i=0;i<word.size();i++){
            if(word[i] == '.'){
                for(int j=0;j<26;j++){
                    if(crawler->children[j] != NULL){
                        if(searchUtil(crawler->children[j], word.substr(i+1)) == true){
                            return true;
                        }
                    }
                }
                return false;
            }else if(crawler->children[word[i]-'a'] == NULL){
                return false;
            }
            crawler=crawler->children[word[i]-'a'];
        }

        if(crawler != NULL && crawler->endOfWord == true){
            return true;
        }
        return false;
    }

    bool search(string word) {
        return searchUtil(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
