class Solution {

private:
    int m, n;

    vector<int> parent;
    vector<int> rank;

    int findP(int x){
        if(parent[x]==x)    return x;
        return parent[x] = findP(parent[x]);
    }

    void Union(int x, int y){
        int pX = findP(x);
        int pY = findP(y);

        if(pX == pY)    return;

        if(rank[pX]>rank[pY]){
            parent[pY] = pX;
        }
        else if(rank[pX]<rank[pY]){
            parent[pX] = pY;
        }
        else{
            parent[pY] = pX;
            rank[pX]++;
        }
    }

    
    vector<pair<int,int>> dir{{0,-1},{-1,0},{0,1},{1,0}};

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();

        parent.resize(m*n);
        rank.resize(m*n,1);

        for(int i = 0;i<m*n;i++){
            parent[i] = i;
        }

        // count the islands
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid2[i][j]==1){
                    // union it's surrounding

                    if(i>0 && grid2[i-1][j]==1){
                        Union(i*n+j,(i-1)*n+j);
                    }

                    if(j>0 && grid2[i][j-1]==1){
                        Union(i*n+j,i*n+j-1);
                    }
                }
            }
        }

        vector<bool> isSubIsland(m*n,true);

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){

                if(grid2[i][j]==1){
                    int par = findP(i*n+j);

                    if(grid1[i][j]==0){
                        isSubIsland[par] = false;
                    }
                }
            }
        }

        int subIslands = 0;
         for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                
                int parIdx = i*n+j;
                if(grid2[i][j]==1 && findP(parIdx)==parIdx && isSubIsland[parIdx]) subIslands++;
            }
        }

        return subIslands;
        
        

    }
};