class LRUCache {
    unordered_map<int,int> key2val;
    list<int> List;
    unordered_map<int, list<int>::iterator> key2iter;    
    int size;
    
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if (key2val.find(key) == key2val.end()) {
            return -1;
        }
        auto iter = key2iter[key];
        List.erase(iter);
        List.push_back(key);
        key2iter[key] = --List.end();
        return key2val[key];
    }
    
    void put(int key, int value) {
        int ret = get(key);
        if (ret != -1) {
            key2val[key] = value;
            return;
        }
        if (key2val.size() == size) {
            int oldkey = *List.begin();
            List.pop_front();
            key2iter.erase(oldkey);
            key2val.erase(oldkey);
        }

        List.push_back(key);
        key2iter[key] = --List.end();
        key2val[key] = value;
        return;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */