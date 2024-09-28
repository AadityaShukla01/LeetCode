class MyCircularDeque {
public:
    // initial values
    int front, rear, size, cap;
    vector<int>arr;
    int k;
    MyCircularDeque(int k) {
        arr.resize(k, -1);
        front = k - 1;
        this->k = k;
        rear = 0;
        cap = k;
        size = 0;
    }
    
    bool insertFront(int value) {
        if(size == cap) return false;
        arr[front] = value;
        // front = (front - 1 + k) % k;
        // or
        front--;
        if(front == -1) front = k - 1;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size == cap) return false;
        arr[rear] = value;
        // rear = (rear + 1) % k;
        // or
        rear++;
        if(rear == k) rear = 0;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size == 0) return false;
        size--;
        front = (front + 1) % k;
        arr[front] = -1;
        return true;
    }
    
    bool deleteLast() {
        if(size == 0) return false;
        size--;
        rear = (rear - 1 + k) % k;
        arr[rear] = -1;
        return true;
    }
    
    int getFront() {
        return arr[(front + 1) % k];
    }
    
    int getRear() {
        return arr[(rear - 1 + k) % k];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */