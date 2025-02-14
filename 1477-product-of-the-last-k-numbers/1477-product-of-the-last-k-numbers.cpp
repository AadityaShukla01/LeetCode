class ProductOfNumbers {
public:
    vector<int>a;
    long long pro;
    ProductOfNumbers() {
        pro = 1;
        a.push_back(1);
    }
    
    void add(int num) {
        pro = pro * num;
        if(pro == 0) {
            pro = 1;
            a.clear();            
        }
        a.push_back(pro);
    }
    
    int getProduct(int k) {
        if(a.size() <= k) return 0;

        return a[a.size() - 1] / a[a.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */