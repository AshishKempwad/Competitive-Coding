int Solution::solve(vector<int> &A)  //Preorder traversal has been given. 
{
    //Preorder traversal can NEVER be in the format "2-3-1"
    // Format(represents) 2(root)-3(left)-1(right).ie. root can never be greater than right element.
    //We use this and check if "231" pattern is present in the list. If present, then we can
    //say that it is NOT a BST.
    //WE USE STACK FOR THIS PURPOSE
    

    //PREORDER STRUCTURE : (ROOT-LEFT-RIGHT)
    
    
    if(A.size() < 1) //Empty tree is a BST
    {
        return 1;
    }
    
    stack<int>s;
    
   int root = INT_MIN;
    
    for(int i=0;i<A.size();i++)
    {
        if(root > A[i])   //As root can never be greater than right element in BST
        {
            return 0;
        }
        
        while(!s.empty() && A[i] > s.top())
        {
            root = s.top();   //update the value of root
            s.pop();
        }
        
        s.push(A[i]);
    }
    
    return 1;  // If we dont find "231" pattern then we can say that it is a BST
}
