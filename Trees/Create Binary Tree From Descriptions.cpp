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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int,TreeNode*>mp; //We use the map to store {key,value} => {nodeValue, Node}
        unordered_set<int>childSet;  //To find the root element.

        for(auto &vec : descriptions){
            int parent = vec[0];
            int child = vec[1];
            int direction = vec[2];

            if(mp.find(parent) == mp.end()){ //Create the parent node if it is not present
                 TreeNode* parentNode = new TreeNode(parent);
                 mp[parent] = parentNode;
            }

            if(mp.find(child) == mp.end()){ //Create the child node if it is not present
                TreeNode* childNode = new TreeNode(child);
                mp[child] = childNode;
            }

            if(direction == 1){  //If 1, then it is left child
                mp[parent] -> left = mp[child];
            }else{    //Else is right child
                mp[parent] -> right = mp[child];
            }

            childSet.insert(child);
        }

        //Finding the root element. If the node is not present in childSet that means it is the root - as root cannot be child of anyone
        for(auto &vec : descriptions){
            int parent = vec[0];
            if(childSet.find(parent) == childSet.end()){
                return mp[parent];
            }
        }

        return NULL;



    }
};
