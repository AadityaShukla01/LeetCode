class MyStack {
public:
    queue<int>input;
    queue<int>output;
    MyStack() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        while(input.size() > 1){
            output.push(input.front());
            input.pop();
        }
        int num = input.front();
        input.pop();
        while(output.empty() == false){
            input.push(output.front());
            output.pop();
        }
        return num;
    }
    
    int top() {
        int num;
        while(input.size() > 0){
            output.push(input.front());
            num = input.front();
            input.pop();
        }
        while(output.empty() == false){
            input.push(output.front());
            output.pop();
        }
        return num;
    }
    
    bool empty() {
        if(input.size()) return false;
        return true;
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