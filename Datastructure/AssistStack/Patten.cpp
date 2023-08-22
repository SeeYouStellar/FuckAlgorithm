class MinStack {
    stack<int> dataStack; // 原始栈
    stack<int> minStack;  // 辅助栈，记录当dataStack中的每一个元素成为dataStack的栈顶元素时，栈中的最小值
public:
    MinStack() {
    }
    
    void push(int val) {
        dataStack.push(val);
        if(minStack.empty() ||minStack.top() > val)minStack.push(val) ;
        else minStack.push(minStack.top());
    }
    
    void pop() {
        dataStack.pop();
        minStack.pop();
    }
    
    int top() {
        return dataStack.top();
    }   
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
