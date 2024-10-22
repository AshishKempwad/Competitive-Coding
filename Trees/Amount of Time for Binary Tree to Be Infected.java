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
##################################################JAVA#############################################

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

     private Map<Integer, List<Integer>> graph = new HashMap<>();
    //Build the graph
       
    public void buildGraph(TreeNode root){
            if(root == null){
                return;
            }
            if(root.left != null){
                graph.computeIfAbsent(root.val,k->new ArrayList<>()).add(root.left.val);
                graph.computeIfAbsent(root.left.val, k->new ArrayList<>()).add(root.val);
            }

            if(root.right != null){
                graph.computeIfAbsent(root.val,k->new ArrayList<>()).add(root.right.val);
                graph.computeIfAbsent(root.right.val,k->new ArrayList<>()).add(root.val);
            }

            buildGraph(root.left);
            buildGraph(root.right);
        }

    public int amountOfTime(TreeNode root, int start) {
         // Edge case handling
        if (root == null) return 0;

        // Reset graph for fresh processing
        graph = new HashMap<>();

        buildGraph(root);
        
        Queue<Integer>q = new LinkedList<>();
        Set<Integer> vis = new HashSet<>();

        q.add(start);
        vis.add(start);
        int time = 0;

        while(!q.isEmpty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                int current = q.poll();

                for(int neighbour : graph.getOrDefault(current, new ArrayList<>())){
                    if(!vis.contains(neighbour)){
                        vis.add(neighbour);
                        q.add(neighbour);
                    }
                }
            }

            if(!q.isEmpty()){
                time++;
            }
        }

        return time;


    }
}
