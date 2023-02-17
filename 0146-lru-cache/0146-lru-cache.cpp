class LRUCache
{
public:
    // list store karega key,value
    list<pair<int, int>> l;

    // map key ko point krta hua iterator jo ki list ke nodes ko point karega o(1)
    unordered_map<int, list<pair<int, int>>::iterator> m;

    // size define kairi
    int size;

    // inititalise
    LRUCache(int capacity)
    {
        size = capacity;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }

    int get(int key)
    {

        // find wheteher key exists in map or not
        if (m.find(key) == m.end())
            return -1;
        // add value to the front of or list
        l.splice(l.begin(), l, m[key]);

        // m key.second matlab value us key ki
        return m[key]->second;
    }

    void put(int key, int value)
    {

        // if key already exis we only update value and put pair into top
        if (m.find(key) != m.end())
        {
            m[key]->second = value;
            l.splice(l.begin(), l, m[key]);
            return;
        }
        if (l.size() == size)
        {
            // removw the last i.e. least recnelty used item from cache
            auto lastKey = l.back().first;
            // removew the last key from map
            l.pop_back();
            // also remove from map
            m.erase(lastKey);

            // aftert his isert the new item
        }
        // insert at front since most recenly used item
        l.push_front({key, value});
        m[key] = l.begin(); // basically map is storing iterator pinting to the nodes of list we are doint so that we can acces the lement of list in o(1) time as asked in question iteratir is like storing the address of nodes
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */