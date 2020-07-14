int getId(int M[MAX][MAX], int n)
{
    
    stack<int>s;
    for(int i=0;i<n;i++)   //people are numbered from 0 to n-1
    {
        s.push(i);    //push all people into the stack
    }
    
    while(s.size() > 1)
    {
        int a = s.top();   //pick two persons at a time for comparsion
        s.pop();
        int b = s.top();
        s.pop();
        
        if(M[a][b]==0)    //'a' doesnt know 'b' , hence 'a' could be a celebrity
        {
            s.push(a);    //hence we push 'a' back to the stack
        }
        else
        {
            s.push(b);    //else the condition is that 'a' knows 'b', hence 'a' is definitely not a celebrity 
                         // and 'b' might be a celebrity, hence we push 'b' back to the stack
        }
    }
    
    int possible_candidate_for_celebrity = s.top();
    bool flag_to_check = true;
    
    for(int i=0;i<n;i++)
    {
        if(i==possible_candidate_for_celebrity)  // we cannot compare with ourselves
        {
            continue;
        }
        
        //Check for two rules to decide if the candidate choosen is the celebrity or not
        //And if he fails any of the rule then he is not the celebrity. Check inversely. 
        
        //Rule 1: Celebrity shouldnt know anyone. If he knows anyone, then he is not the celebrity.
        
        //Rule 2: Everyone(except celebrity) should know him. If any of the person doesnt know him, 
        //        then he is not the celebrity. 
        
        if(M[possible_candidate_for_celebrity][i]==1 || M[i][possible_candidate_for_celebrity]==0)
        {
            flag_to_check = false;
        }
    }
    
    if(flag_to_check == false)
    {
        return -1;
    }
    
    return possible_candidate_for_celebrity;
    
    //Your code here
}
