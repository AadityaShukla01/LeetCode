class LFUCache {
public:
    map<int, list<vector<int>>::iterator> m;
    map<int, list<vector<int>>> cache;
    int size;
    int cap;
    LFUCache(int capacity) {
        size = 0;
        cap = capacity;
    }

    int get(int key) {
        if (m.find(key) == m.end())
            return -1;

        auto &v = *(m[key]);
        // v -> {key, value, counter}
        int counter = v[2];
        int value = v[1];

        cache[counter].erase(m[key]);
        if (cache[counter].size() == 0) {
            cache.erase(counter);
        }
        counter++;
        cache[counter].push_front({key, value, counter});
        m[key] = cache[counter].begin();
        return value;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            auto &v = *(m[key]);
            // v -> {key, value, counter}
            int counter = v[2];

            cache[counter].erase(m[key]);
            if (cache[counter].size() == 0) {
                cache.erase(counter);
            }
            counter++;
            cache[counter].push_front({key, value, counter});
            m[key] = cache[counter].begin();
        } else if (size < cap) {
            cache[1].push_front({key, value, 1});
            m[key] = cache[1].begin();
            size++;
        } else {
            // LFU
            auto &v = cache.begin()->second;
            int counter = v.back()[2];
            m.erase(v.back()[0]);
            cache[counter].pop_back();

            if (cache[counter].size() == 0)
                cache.erase(counter);

            cache[1].push_front({key, value, 1});
            m[key] = cache[1].begin();
        }
    }
};