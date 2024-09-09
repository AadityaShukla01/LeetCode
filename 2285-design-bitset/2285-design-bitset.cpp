class Bitset {
public:
    vector<int>bitset;
    int ones;
    int flips = 0;
    int size;
    Bitset(int size) {
        ones = 0;
        this->size = size;
        bitset.resize(size, 0);
    }
    
    void fix(int idx) {
        if(flips % 2 == 0){
            if(bitset[idx] == 0){
                ones++;
                bitset[idx] = 1;
            }
        }
        else{
            if(bitset[idx] == 1){
                ones++;
                bitset[idx] = 0;
            }
        }
    }
    
    void unfix(int idx) {
        if(bitset[idx] == 1 && flips % 2 == 0){
            ones--;
            bitset[idx] = 0;
        }
        else if(bitset[idx] == 0 && flips % 2){
            ones--;
            bitset[idx] = 1;
        }
    }
    
    void flip() {
        ones = size - ones;
        flips++;
    }
    
    bool all() {
        return ones == size;
    }
    
    bool one() {
        return ones > 0;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        string res = "";
        for(auto el: bitset)
        {
            if(flips % 2 == 0)
            {
                res += to_string(el);
            }
            else
            {
                res += to_string(1 - el);
            }
        }
        return res;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */