class MedianFinder {
public:
    priority_queue<double>left;
    priority_queue<double, vector<double>, greater<double>>ryt;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // did this 3 steps to maitanin a sorted order left -> min & rest ryt
        left.push(num);
        ryt.push(left.top());
        left.pop();
        // left should never hless elements than ryt
        if(left.size() < ryt.size()){
            left.push(ryt.top());
            ryt.pop();
        }
    }
    
    double findMedian() {
        if((left.size() + ryt.size()) % 2 == 0){
            return (left.top() + ryt.top())/2.0;
        }
        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */