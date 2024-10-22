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

##########################################JAVA##########################################################


/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode createBinaryTree(int[][] descriptions) {
        Map<Integer, TreeNode> nodeMap = new HashMap<>();
        Set<Integer> children = new HashSet<>();

        // Step 1: Build the tree graph and mark children
        for (int[] description : descriptions) {
            int parent = description[0];
            int child = description[1];
            int isLeft = description[2];

            // Create parent node if not already created
            TreeNode parentNode = nodeMap.getOrDefault(parent, new TreeNode(parent));
            nodeMap.put(parent, parentNode);

            // Create child node if not already created
            TreeNode childNode = nodeMap.getOrDefault(child, new TreeNode(child));
            nodeMap.put(child, childNode);

            // Link child to parent as left or right
            if (isLeft == 1) {
                parentNode.left = childNode;
            } else {
                parentNode.right = childNode;
            }

            // Mark child as a non-root node
            children.add(child);
        }

        // Step 2: Find the root node (it won't be in the set of children)
        TreeNode root = null;
        for (int[] description : descriptions) {
            int parent = description[0];
            if (!children.contains(parent)) {
                root = nodeMap.get(parent);
                break;
            }
        }

        return root;
    }
}
