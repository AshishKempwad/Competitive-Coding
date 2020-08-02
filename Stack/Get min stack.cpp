class MinStack {
public:
    /** initialize your data structure here. */
     stack<int> s;
        stack<int>minstack;
    MinStack() {
        
       
    }
    
    void push(int x) 
    {
        s.push(x);
        
        if(minstack.empty())
        {
            minstack.push(x);
        }
        else if(minstack.top() > x)
        {
            minstack.push(x);
        }
        else if(minstack.top() <= x)
        {
            minstack.push(minstack.top());
        }
        
    }
    
    void pop() 
    {
       s.pop();
        minstack.pop();
    }
    
    int top()
    {
        int x = s.top();
        return x;
    }
    
    int getMin()
    {
        int minele = minstack.top();
        return minele;
    }
};
