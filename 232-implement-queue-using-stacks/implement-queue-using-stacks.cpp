class MyQueue {
public:
    stack<int>st;
    stack<int>st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st.empty()){
            int top=st.top();
            st.pop();
            st2.push(top);
        }
        st.push(x);
         while(!st2.empty()){
            int top=st2.top();
            st2.pop();
            st.push(top);
        }
    }
    
    int pop() {
        int top=st.top();
        st.pop();
        return top;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */