class RandomizedSet {
public:
    vector<int> v;
    int index=0;
    unordered_map<int,int> map;
    RandomizedSet() {
        index=0;
        v.clear();
        map.clear();
    }
    
    bool insert(int val) {
        if(map.find(val)!=map.end()){
            return false;
        }
        map[val]=index++;
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(map.find(val)==map.end()){
            return false;

        }
        int i=map[val];
        swap(v[i],v[index-1]);
        map[v[i]]=i;
        v.pop_back();
        index--;
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        int i= rand()%index;
        return v[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */