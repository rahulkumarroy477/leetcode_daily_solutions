class LFUCache {
public:
    int cap;
    int size;

    unordered_map<int,list<vector<int>>::iterator> mp;
    map<int,list<vector<int>>> freq;   // counter-->   {key,value,counter}
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    void makeMostFrequentlyUsed(int key){
        auto &vec = *mp[key];   // & is used so that original me update ho naki copy ho
        int value = vec[1];
        int f = vec[2];

        freq[f].erase(mp[key]);
        // empty ho gaya
        if(freq[f].empty()){
            freq.erase(f);
        }
        f++;
        freq[f].push_front({key,value,f});
        // updating the addres in mp
        mp[key] = freq[f].begin();
    }
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        
        // find address of the key node
        auto vec = *mp[key];    // key,value,count
        int value = vec[1];
        // count is updated as we have used it 
        makeMostFrequentlyUsed(key);

        return value;

    }
    
    void put(int key, int value) {
        if(cap==0){
            return;
        }
        if(mp.find(key)!=mp.end()){
            auto &vec = *mp[key];
            vec[1] = value;
            makeMostFrequentlyUsed(key);
        }
        else if(size<cap){
            // fresh banda
            size++;
            freq[1].push_front({key,value,1});
            mp[key] = freq[1].begin();
        }
        else{
            // time to remove
            auto &kaunSaList = freq.begin()->second;
            int key_to_delete = kaunSaList.back()[0];
            kaunSaList.pop_back();

            if(kaunSaList.empty()){
                freq.erase(freq.begin()->first);    // map ka top
            }

            freq[1].push_front({key,value,1});
            mp.erase(key_to_delete);
            mp[key] = freq[1].begin(); 
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */