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
    void constructGraph(TreeNode* root,unordered_map<int,vector<int>>&graph){
        if(!root){
            return;
        }
        if(root->left){
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            constructGraph(root->left,graph);
        }
        if(root->right){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            constructGraph(root->right,graph);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>graph;
        constructGraph(root,graph);
        queue<int>q;
        vector<bool>vis(100001,false);
        int timer = -1;
        q.push(start);
        vis[start]=true;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr = q.front();
                q.pop();

                for(auto &ele : graph[curr]){
                    if(!vis[ele]){
                        q.push(ele);
                        vis[ele]=true;
                    }
                }      
            }
            timer++;
        }
        return timer;
    }
};
