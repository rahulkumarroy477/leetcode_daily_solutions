class RandomizedSet {
public:
    vector<int> vec;
    unordered_map<int,int> mp;  // val, index
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())  return false;

        int n = vec.size();
        vec.push_back(val);
        mp[val] = n;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())  return false;

        int idx = mp[val];
        std::swap(vec[idx],vec[vec.size()-1]);
        vec.pop_back();
        mp[vec[idx]] = idx;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = vec.size();

        if(n==0)    return 0;
        int idx = rand()%n;
        return vec[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */