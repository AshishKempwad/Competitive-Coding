/* 
	This question can be solved by assigning horizontal distance
	in order of X coordinate.
	
	For Example:
	------------
	NOTE: Distance of root is considered as 0
		  No need to maintain Y coordinates.	
	Number written inside parenthesis denote the horizontal distance of that node.
	
		Node has distance: d
		Left Children:	   d - 1
		Right Children:	   d + 1
		
	
				1(0)
			  /     \
		 (-1)2       3(1)	
		   /  \		/   \
	  (-2)4   5(0) 6(0) 7(2)

	***The catch point of this question is:
	---------------------------------------	
	If two nodes have the same position, then the value of
	the node that is reported first is the value that is smaller.
	
	What it means: If two nodes have same position and both are present
	in same level.
	
	For such type of cases the nodes having smaller value comes first.
	Like in the above tree 5 and 6 have same position and present in second level.
	since 5 is smaller than 6 so there fore 5 should be comes first.

	To handle it, i maintained level number alongwith with node value of a node.
	by using vector<pair<int, int>>.
	
	To get horizontal distances in sorted order i maintained map data structure.
	----------------------------------------------------------------------------
	Content of _map for the above tree is: map<int, vector<pair<int, int>>> _map
	
hori_dist(key)     [levl_number, element]    
		
	-2     -->      [(2, 4)]
	-1     --> 		[(1, 2)]
	0      --> 		[(0, 1), (2, 5), (2, 6)]
	1      --> 		[(1, 3)]
	2      --> 		[(2, 7)]
	
	While getting content of _map from top to bottom sort the vector 
	associated with key based on level number. If level are same for
	the two element then sort based on values.
	
	We don't need to pass custom comparator to sort function.
	because sort functin will automatically do it.
	
	I hope you're able to understood my point.
	If you like it then please upvote my solution.
	
	Thank You.  */
  
  
  
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
    
     map<int, multiset<pair<int, int>>> mp; //MultiSet stores the value in the sorted manner. Here we are using pair inside the set, so in this case it will sort 
    // based on the first value and if the first value is similar it will sort based on the second value. Hence " multiset<pair<int,int>> " is very useful data structure in such cases.
   //multiset allows duplicates unlike sets.
    
    void dfs(TreeNode* root, int horizontal_dist,int vertical_dist)
    {
        if(!root)
        {
            return;
        }
        mp[horizontal_dist].insert({vertical_dist,root->val});  
        dfs(root->left,horizontal_dist-1,vertical_dist+1);
        dfs(root->right,horizontal_dist+1,vertical_dist+1);
    }
 
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        if(!root)
        {
            return {};
        }

        dfs(root,0,0);
        vector<vector<int>>res;
        for(auto in_map : mp)
        {
            vector<int>v;
            for(auto x : in_map.second)
            {
                v.push_back(x.second);
            }
            res.push_back(v);
        }
        return res;
        
        
    }
};
