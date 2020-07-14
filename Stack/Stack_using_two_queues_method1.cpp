//In this Method, Push takes O(N) time and pop takes O(1) time.

void QueueStack :: push(int x)
{
    q2.push(x);
    
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    
    while(!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
        // Your Code
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    if(q1.empty())
    {
        return -1;
    }
    
    int x = q1.front();
  
    q1.pop();
    return x;
    
        // Your Code       
}
