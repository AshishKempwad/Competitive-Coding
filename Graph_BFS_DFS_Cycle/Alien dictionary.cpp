/*

Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer N and k denoting the size of the dictionary. Then in the next line are sorted space separated values of the alien dictionary.

Output:
For each test case in a new line output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findOrder() which takes the string array dict[], its size N and the integer K as inputs and returns a string denoting the order of characters in the alien language.

Expected Time Complexity: O(N + K).
Expected Auxiliary Space: O(K).

Constraints:
1 <= T <= 1000
1 <= N <= 300
1 <= k <= 26
1 <= Length of words <= 50

Example:
Input:
2
5 4
baa abcd abca cab cad
3 3
caa aaa aab

Output:
1
1

Explanation:
Test Case 1:
Input:  Dict[ ] = { "baa", "abcd", "abca", "cab", "cad" }, k = 4
Output: Function returns "bdac"
Here order of characters is 'b', 'd', 'a', 'c'
Note that words are sorted and in the given language "baa"
comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.

Test Case 2:
Input: Dict[] = { "caa", "aaa", "aab" }, k = 3
Output: Function returns "cab"


*/



// User function Template for C++

/*
dict : array of strings denoting the words in alien langauge
N : Size of the dictionary
K : Number of characters
*/


string findOrder(string dict[], int N, int K) 
{
    //This is a classic example of Topological sorting.
    //We will use famous Kahn's algorithm
    
    unordered_set<char>nodes;
    unordered_map<char,vector<char>>graph;
    unordered_map<char,int>indegree;
    
    //This function counts the nodes
    for(int i=0;i<N;i++)
    {
        string word = dict[i];
        for(char c : word)
        {
            nodes.insert(c);
        }
    }
    
    //Put directed edges. The directed edge will be from alien's lexographically lower word to alien's lexographically bigger word.
    for(int i=1;i<N;i++)
    {
        string smaller = dict[i-1];
        string larger = dict[i];

        for(int j=0;j<smaller.size() && j<larger.size();j++)
        {
            if(smaller[j]!=larger[j])
            {
                graph[smaller[j]].push_back(larger[j]);
                indegree[larger[j]]++;
                break;
            }
        }
        
    }
    
    
    queue<char>q;
    string order="";
    
   for(char x : nodes)
   {
       if(indegree[x]==0)
       {
           q.push(x);
       }
   }
   
   while(!q.empty())
   {
       char curr = q.front();
       q.pop();
       
       order+=curr;
       
       for(char neighbours : graph[curr])
       {
           indegree[neighbours]--;
           if(indegree[neighbours]==0)
           {
               q.push(neighbours);
           }
           
       }
   }
    
    return order;
     
}
