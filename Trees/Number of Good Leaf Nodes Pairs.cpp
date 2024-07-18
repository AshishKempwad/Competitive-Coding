//Approach 1 : Brute Force TC =O(n^3) - Gives TLE

class Solution {
public:


    void findLeafNodes(TreeNode* root, vector<TreeNode*>&leafNodes){
        if(!root){
            return;
        }

        if(root->left == NULL & root->right == NULL){
            leafNodes.push_back(root);
        }

        findLeafNodes(root->left,leafNodes);
        findLeafNodes(root->right,leafNodes);

    }

    TreeNode* findLca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return NULL;
        }

        if(root == p || root == q){
            return root;
        }
        
        TreeNode* left = findLca(root->left,p,q);
        TreeNode* right = findLca(root->right,p,q);
        if(left && right){
            return root;
        }

        if(left){
            return left;
        }

        return right;
    }

    int findDist(TreeNode* root, TreeNode* target, int dist){
        if(!root){
            return -1;
        }
        if(root == target){
            return dist;
        }

        int left = findDist(root->left,target,dist+1);

        if(left == -1){
            int right = findDist(root->right,target,dist+1);
            return right;
        }

        return left;

    }

    int countPairs(TreeNode* root, int distance) {
        /*Approach 1:
           1. Find all leaf nodes
           2. Find lca of all leaf nodes
           3. If the distance between the two leaf nodes is less than or equal to distance(given) then increase the count
        */
        vector<TreeNode*>leafNodes;
        findLeafNodes(root,leafNodes);
        int count = 0;

        for(int i=0;i<leafNodes.size()-1;i++){
            for(int j=i+1;j<leafNodes.size();j++){
                TreeNode* lca = findLca(root,leafNodes[i],leafNodes[j]);
                int dist1 = findDist(lca,leafNodes[i],0);
                int dist2 = findDist(lca,leafNodes[j],0);

                if(dist1+dist2 <= distance){
                    count++;
                }
            }
        }

        return count;

        
    }
};


//Approach 2 TC = O(n^2)

class Solution {
public:

    void makeGraph(TreeNode* root,unordered_set<TreeNode*>&leafNodes,unordered_map<TreeNode*,vector<TreeNode*>>&graph,TreeNode* &parent){
        if(!root){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            leafNodes.insert(root);   //We find and add all leaf nodes
        }

        if(parent != NULL){
            graph[root].push_back(parent);
            graph[parent].push_back(root);
        }

        makeGraph(root->left,leafNodes,graph,root);
        makeGraph(root->right,leafNodes,graph,root);
    }


    int countPairs(TreeNode* root, int distance) {
        /* Approach 2:
           1. Construct an unordered graph - adjcency list
           2. Find the leaf nodes
           3. Apply DFS from leaf node and check if you can reach any other leaf node in given distance
        */

        unordered_set<TreeNode*>leafNodes;
        unordered_map<TreeNode*,vector<TreeNode*>>graph;
        TreeNode* parent = NULL;  //Root doesnt have a parent
        makeGraph(root,leafNodes,graph,parent);
        int count = 0;

        for(auto &leafNode : leafNodes){
               queue<TreeNode*>q;
               unordered_set<TreeNode*>visited;
               q.push(leafNode);
               visited.insert(leafNode);

            for(int i=0;i<=distance;i++){  //BFS from every leafnode only till distance that is given

                int size = q.size();
               while(size--){
                   
                   TreeNode* curr = q.front();
                   q.pop();

                   if(curr != leafNode && leafNodes.count(curr) > 0){
                     //Not a same leaf node && It must be a leaf node
                     count++;
                   }
                   for(auto & neighbour : graph[curr]){
                       if(!visited.count(neighbour)){
                          q.push(neighbour);
                          visited.insert(neighbour);
                       }
                   }
               }
            }
        }

        return count/2;   //As we check from leafNode1 to leafNode2 and also from leafNode2 to leafNode1. Hence it is a duplicate pair. Hence divide by 2.
    }
};
