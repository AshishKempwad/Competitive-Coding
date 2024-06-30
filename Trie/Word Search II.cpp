class Solution {
public:
   // Structure of trieNode
    struct trieNode{
        bool endOfWord;
        string word;
        trieNode* children[26];
    };

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

   //Method to create and get the new node
    trieNode* getNode(){
        trieNode* newNode = new trieNode();
        newNode->endOfWord = false;
        newNode->word = "";

        for(int i=0;i<26;i++){
            newNode->children[i] = NULL;
        }

        return newNode;
    }

   //Inserting into trie datastructure
    void insert(trieNode* root, string &word){
        trieNode* crawler = root;

        for(int i=0;i<word.size();i++){
            char ch = word[i]-'a';
            
            //If this character is present, we create it using getNode function
            if(crawler->children[ch] == NULL){
                crawler->children[ch] = getNode();
            }
            crawler = crawler->children[ch]; // Need to increment the crawler to next character that we have inserted
        }

        crawler->endOfWord = true;
        crawler->word = word;
    }

    void findTrieNodes(int i, int j, int n, int m, vector<vector<char>>& board, trieNode* root, vector<string>&res){
        //If it is out of bound OR visited(using '$') then return
        if( i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '$'){
            return;
        }
         
         //If the character is not present, then no point of going ahead and we return
        if(root->children[board[i][j] - 'a'] == NULL){ 
            return;
        }

        root = root->children[board[i][j] - 'a'];

        if(root->endOfWord == true){
            res.push_back(root->word);
            root->endOfWord = false;     //Marking it as false, as we have already added it to res vector
        }

        char temp = board[i][j];
        board[i][j] = '$';   //Marking it as visited

        for(int k=0;k<4;k++){
            int i_ = i + dx[k];
            int j_ = j + dy[k];

            findTrieNodes(i_,j_,n,m,board,root,res);
        }
        board[i][j] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n = board.size();
        int m = board[0].size();

        vector<string>res;

        trieNode* root = getNode();

       //Inserting words in the trie
        for(auto &word : words){
             insert(root,word);
        }

       //Looping over the board
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char boardCharacter = board[i][j];
                if(root->children[boardCharacter - 'a'] != NULL){  //If the character on the board is present in trie
                      findTrieNodes(i,j,n,m,board,root,res);
                }
                
            }
        }

        return res;
    }
};
