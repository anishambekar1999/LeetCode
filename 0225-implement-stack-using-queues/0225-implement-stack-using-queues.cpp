class MyStack {
public:
    queue<int>q1;
    queue<int>q2;

    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        
        int ans=-1;
        while(!q1.empty())
        {
            int x=q1.front();
            q1.pop();

            if(!q1.empty())
                q2.push(x);
            else
                ans=x;
            
        }

        while(!q2.empty())
        {
            int x=q2.front();
            q2.pop();
            q1.push(x);
        }
        return ans;
    }
    
    int top() {

        int ans=-1;
        while(!q1.empty())
        {
            int x=q1.front();
            q1.pop();

            if(q1.empty())
                ans=x;
            q2.push(x);
        }

        while(!q2.empty())
        {
            int x=q2.front();
            q2.pop();
            q1.push(x);
        }
        return ans;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */