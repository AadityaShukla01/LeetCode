class CustomStack {
public:
    int size;
    vector<int>a;
    int ptr;
    CustomStack(int maxSize) {
        a.resize(maxSize);
        size = maxSize;
        ptr = -1;
    }
    
    void push(int x) {
        if(ptr < size - 1){
            ptr++;
            a[ptr] = x;
        }
    }
    
    int pop() {
        if(ptr == -1) return -1;
        int el = a[ptr];
        ptr--;
        return el;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<min(k, ptr + 1); i++)
        {
            a[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */