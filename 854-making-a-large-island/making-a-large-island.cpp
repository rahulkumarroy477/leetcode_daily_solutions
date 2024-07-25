class Solution {
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<int> parent;
vector<int> size;

bool check(int x, int y, int m, int n){
    if(x<m && x>=0 && y<n && y>=0)  return true;
    return false;
}
int find(int node){
    if(parent[node]==node)
        return node;
    return parent[node] = find(parent[node]);
}

void Union(int a, int b){
    int pa = find(a);
    int pb = find(b);

    if(pa == pb)    return;

    if(size[pa]>=size[pb]){
        parent[pb] = pa;
        size[pa] += size[pb];
    }
    else {
        parent[pa] = pb;
        size[pb] += size[pa];
    }
}
public:
    int largestIsland(vector<vector<int>>& grid) {
        

        int m = grid.size();
        int n = grid[0].size();
        parent.resize(m*n);
        size.resize(m*n,1);

        for(int i = 0;i<m*n;i++)
            parent[i] = i;


        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    for(int k = 0;k<4;k++){
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if(check(ni,nj,m,n)){
                            if(grid[ni][nj]==1){
                                int node1 = (i*n)+j;
                                int node2 = (ni*n) + nj;

                                Union(node1,node2);
                            }
                        }
                    }

                }

            }
        }
        
        int ans = 0;
        for(int i =0;i<m*n;i++){
            ans = max(ans,size[parent[i]]);
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==0){
                    set<int> st;

                    for(int k = 0;k<4;k++){
                        int ni = i + dx[k];
                        int nj = j + dy[k];

                        if(check(ni,nj,m,n)){
                            if(grid[ni][nj]==1){
                                int node1 = ni*n+nj;
                                st.insert(find(node1));
                                
                            }
                        } 
                    }

                    int temp = 1;
                    while(!st.empty()){
                        int elem = *st.begin();
                        st.erase(elem);

                        temp += size[elem];
                    }

                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};