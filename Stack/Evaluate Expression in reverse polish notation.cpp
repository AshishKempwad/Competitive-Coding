int Solution::evalRPN(vector<string> &A)
{
    
    stack<int>st;
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=="/" || A[i]=="+" || A[i]=="-" || A[i]=="*")
        {
             int temp2 = st.top();
            st.pop();
            int temp1 = st.top();
            st.pop();
            
           if(A[i]=="+")
           {
               temp1 = temp2+temp1;
           }
           else if(A[i]=="/")
           {
               temp1 = temp1 / temp2;
           }
           else if(A[i]=="*")
           {
               temp1 = temp1 * temp2;
           }
           else if(A[i]=="-")
           {
               temp1 = temp1 - temp2;
           }
            
            st.push(temp1);
            
        }
        else
        {
          int x = stoi(A[i]);
            st.push(x);
        }
    }
    
    return st.top();

}
