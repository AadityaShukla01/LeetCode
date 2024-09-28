class MyCircularQueue {
public:
    int front, size, rear, cap;
    int k;
    vector<int>arr;
    MyCircularQueue(int k) {
        arr.resize(k, -1);
        this->k = k;
        front = k - 1, rear = front, size = 0, cap = k;
    }
    
    bool enQueue(int value) {
        if(size == cap) return false;
        arr[front] = value;
        front = (front - 1 + k) % k;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size == 0) return false;
        size--;
        rear = (rear - 1 + k) % k;
        return  true;
    }
    
    int Front() {
        if(size == 0) return -1;
        return arr[rear];
    }
    
    int Rear() {
        if(size == 0) return -1;
        return arr[(front + 1) % k];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */