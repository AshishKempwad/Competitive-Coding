// Approach 1: By constructing graph(adjaceny list) and BFS
// TC = O(n) SC = O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

     string findShortestPath(int startValue, int destValue, unordered_map<int,vector<pair<int,char>>>&graph){
         unordered_set<int>visited;
         queue<pair<int,string>>q;

         q.push({startValue,""});

         while(!q.empty()){
              
              auto [currentVal, path] = q.front();
              q.pop();

              if(currentVal == destValue){
                return path;
              }

              for(auto [neighbour,direction] : graph[currentVal]){
                  if(!visited.count(neighbour)){
                     visited.insert(neighbour);
                     q.push({neighbour,path+direction});
                  }
              }
         }

         return "";
     }

    void buildGraph(TreeNode* node, unordered_map<int,vector<pair<int,char>>>&graph, TreeNode* parent){

        if(!node){
            return;
        }

        if(parent){
            graph[node->val].push_back({parent->val,'U'});
            graph[parent->val].push_back({node->val, parent->left == node ? 'L' : 'R'});
        }

        buildGraph(node->left,graph,node);
        buildGraph(node->right,graph,node);

    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<int,vector<pair<int,char>>>graph;
        TreeNode* parent = NULL;
        buildGraph(root,graph,parent);
        return findShortestPath(startValue, destValue,graph);

    }
};




//Approach 2 : By finding LCA
//TC = O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findLCA(TreeNode* root, int p, int q){

        if(!root){
            return NULL;
        }

        if(root->val == p || root->val == q){
            return root;
        }

        TreeNode* leftN = findLCA(root->left,p,q);
        TreeNode* rightN = findLCA(root->right,p,q);

        if(leftN && rightN){
            return root;
        }

        if(leftN){
            return leftN;
        }

        return rightN;

    }

    bool findPath(TreeNode* lca, int target, string &path){
        if(lca == NULL){
            return false;
        }

        if(lca->val == target){
            return true;
        }

        //explore left
        path.push_back('L');
        if(findPath(lca->left,target,path) == true){
            return true;
        }
        path.pop_back();

       //explore right
        path.push_back('R');
        if(findPath(lca->right,target,path) == true){
            return true;
        }
        path.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        TreeNode* lca = findLCA(root,startValue, destValue);

        /* STEPS :
           1. Find LCA of two node values given
           2. Find the path from lca to startValue - lcaToStartValue
           3. Find the oath from lca to destValue. - lcaToDestValue
           4. Put 'U' in for len(lcaToStartValue)
           5. Then concatenate step 4 and lcaToDestValue
        */

        string lcaToStartValue = "";
        string lcaToDestValue = "";

        findPath(lca, startValue, lcaToStartValue);
        findPath(lca, destValue, lcaToDestValue);

        string res = "";

        for(int i=0;i<lcaToStartValue.length();i++){
            res.push_back('U');
        }

        res += lcaToDestValue;

        return res;
    }
};



/*Approach 3 : 
  1. Find the path from root to startValue
  2. Find the path from root to destValue
  3. Compare both the paths that we got from step1 and step2.
  4. Keep iterating further until both the paths match.
  5. The point at which they dont match would be the point of lca.
  6. Then from that point onwards, replace/add 'U' till path1 ends - remaining length of path1
  7. Then concatenate path2 with path1.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool findPath(TreeNode* root, int target, string &path){
        if(!root){
            return false;
        }

        if(root->val == target){
            return true;
        }

        path.push_back('L');
        if(findPath(root->left,target,path) == true){
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if(findPath(root->right,target,path) == true){
            return true;
        }
        path.pop_back();

        return false;

    }


    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootToStartValuePath = "";
        string rootToDestValuePath = "";

        findPath(root,startValue,rootToStartValuePath);
        findPath(root,destValue,rootToDestValuePath);

        int l = 0;  //This indicates the length of common match

        while(l < rootToStartValuePath.size() && l < rootToDestValuePath.size() && rootToStartValuePath[l] == rootToDestValuePath[l]){
            l++;
        }

        string res = "";
        for(int i=l;i<rootToStartValuePath.size();i++){
               res.push_back('U');
        }

        for(int i=l;i<rootToDestValuePath.size();i++){
            res.push_back(rootToDestValuePath[i]);
        }

        return res;

    }
};



