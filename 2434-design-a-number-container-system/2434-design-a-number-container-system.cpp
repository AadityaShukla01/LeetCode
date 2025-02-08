class NumberContainers {
public:
    map<int, multiset<int>> mp1;
    map<int, int> mp2;
    NumberContainers() {}

    void change(int index, int newNumber) {
        if (mp2.find(index) != mp2.end()) {
            int number = mp2[index];
            auto it = mp1[number].find(index);
            if(it != mp1[number].end())
                mp1[number].erase(it);
            mp1[newNumber].insert(index);
            mp2[index] = newNumber;
        }
        else {
            mp2[index] = newNumber;
            mp1[newNumber].insert(index);
        }
    }

    int find(int number) {
        if(mp1[number].size() == 0) return -1;

        return *mp1[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */