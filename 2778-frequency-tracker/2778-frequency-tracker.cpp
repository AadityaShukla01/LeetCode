class FrequencyTracker {
public:
    unordered_map<int, int>m;
    map<int, int>trac;
    FrequencyTracker() {
        m.clear();
        trac.clear();
    }
    
    void add(int number) {
        trac[m[number]]--;
        m[number]++;
        trac[m[number]]++;
    }
    
    void deleteOne(int number) {
        if(m[number] == 0 || m.find(number) == m.end())
            return;
        trac[m[number]]--;
        m[number]--;
        trac[m[number]]++;
        
    }
    
    bool hasFrequency(int frequency) {
        if(trac.find(frequency) == trac.end()) return false;
        return trac[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */