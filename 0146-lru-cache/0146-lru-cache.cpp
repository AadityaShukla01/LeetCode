class LRUCache {
public:
    list<vector<int>>cache;
    unordered_map<int, list<vector<int>>::iterator> m; // key -> address
    int size;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        auto v = *(m[key]);
        auto val = v[1];
        
        cache.erase(m[key]);
        cache.push_front({key, val});
        m[key] = cache.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            auto v = *(m[key]);
            cache.erase(m[key]);
            cache.push_front({key, value});
            m[key] = cache.begin();
        }
        else if(size < cap){
            cache.push_front({key, value});
            m[key] = cache.begin();
            size++;
        }
        else{
            // LRU CACHE
            auto k = cache.back()[0];
            m.erase(k);
            cache.pop_back();

            cache.push_front({key, value});
            m[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */