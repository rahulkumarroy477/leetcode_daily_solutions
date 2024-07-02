class Solution {
private:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]==x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a, int b){
        int parentA = find(a);
        int parentB = find(b);

        if(parentA == parentB)  return;

        if(rank[parentA]>rank[parentB]){
            parent[parentB] = parentA;
        }
        else if(rank[parentA]<rank[parentB]){
            parent[parentA] = parent[parentB];
        }
        else{
            parent[parentB] = parentA;
            rank[parentA]++;
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26,0);

        for(int i = 0;i<26;i++)
            parent[i] = i;
        // using dsu

        for(string &eq:equations){
            int a = eq[0]-'a';
            int b = eq[3]-'a';
            if(eq[1]=='='){
                Union(a,b);
            } 
        }
        for(string &eq:equations){
            int a = eq[0]-'a';
            int b = eq[3]-'a';
            if(eq[1]=='!'){
                int pA = find(a);
                int pB = find(b);

                if(pA == pB)    return false;
            } 
        }

        return true;
    }
};