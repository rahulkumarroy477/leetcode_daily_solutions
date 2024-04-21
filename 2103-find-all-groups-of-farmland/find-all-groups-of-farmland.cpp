class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        
        int m = land.size();
        int n = land[0].size();
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(land[i][j] == 1){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    land[i][j] = 0;
                    int last_r = 0, last_c = 0;
                    while(!q.empty()){
                        last_r = q.front().first;
                        last_c = q.front().second;
                        
                        q.pop();
                        
                        vector<int> rows = {0,-1,0,1};
                        vector<int> cols = {-1,0,1,0};
                        
                        for(int j = 0;j<4;j++){
                            int new_r = last_r + rows[j];
                            int new_c = last_c + cols[j];
                            
                            if(new_r>=0 and new_c>=0 and new_r<m and new_c<n and land[new_r][new_c]==1){
                                q.push({new_r,new_c});
                                land[new_r][new_c] = 0;
                            }
                        }
                    }
                    
                    ans.push_back({i,j,last_r,last_c});
                }
            }
        }
        
        return ans;
    }
};