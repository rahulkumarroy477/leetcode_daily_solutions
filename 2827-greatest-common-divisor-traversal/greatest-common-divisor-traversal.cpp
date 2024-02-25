class DSU {
private:
    vector<int> parent;
public:
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void Union(int x, int y) {
        parent[find(x)] = find(y);
    }
    
    int countOfcomponents() {
        int count = 0;
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] == i)
                count++;
        }
        return count;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        
        DSU dsu(n);
        unordered_map<int,int> mp;
        
        for(int i = 0; i < n; ++i) {
            for(int factor = 2; factor * factor <= nums[i]; ++factor) {
                if(nums[i] % factor != 0)   continue;
                
                if(mp.find(factor) != mp.end()) {
                    int idx = mp[factor];
                    dsu.Union(idx, i);
                }
                else {
                    mp[factor] = i;
                }
                
                while(nums[i] % factor == 0)    nums[i] /= factor;
            }
            
            if(nums[i] > 1) {
                if(mp.find(nums[i]) != mp.end()) {
                    int idx = mp[nums[i]];
                    dsu.Union(idx, i);
                }
                else {
                    mp[nums[i]] = i;
                }
            }
        }
        
        return dsu.countOfcomponents() == 1;
    }
};