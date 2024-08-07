class Solution {
    vector<vector<int>> fireTime;
    int m, n;
    vector<pair<int, int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    bool check(int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }
    
    void updateFireTime(vector<vector<int>>& grid) {
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        int currTime = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    fireTime[i][j] = currTime;
                    vis[i][j] = true;
                } else if (grid[i][j] == 2) {
                    fireTime[i][j] = -1;
                }
            }
        }
        
        while (!q.empty()) {
            currTime++;
            int size = q.size();
            for (int s = 0; s < size; s++) {
                auto [i, j] = q.front();
                q.pop();
                
                for (auto [dx, dy] : directions) {
                    int new_i = i + dx;
                    int new_j = j + dy;
                    
                    if (check(new_i, new_j) && !vis[new_i][new_j] && fireTime[new_i][new_j] != -1) {
                        fireTime[new_i][new_j] = currTime;
                        vis[new_i][new_j] = true;
                        q.push({new_i, new_j});
                    }
                }
            }
        }
    }
    
    bool isPossible(int mid) {
        int currTime = mid;
        if (fireTime[0][0] <= currTime) return false;
        
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = true;
        
        while (!q.empty()) {
            currTime++;
            int size = q.size();
            for (int s = 0; s < size; s++) {
                auto [i, j] = q.front();
                q.pop();
                
                for (auto &[dx, dy] : directions) {
                    int new_i = i + dx;
                    int new_j = j + dy;
                    
                    if (new_i == m - 1 && new_j == n - 1 && 
                    currTime<=fireTime[new_i][new_j]) return true;
                    
                    if (check(new_i, new_j) && !vis[new_i][new_j] &&
                    fireTime[new_i][new_j] != -1 && 
                    currTime < fireTime[new_i][new_j]) {
                        vis[new_i][new_j] = true;
                        q.push({new_i, new_j});
                    }
                }
            }
        }
        
        return false;
    }
    
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return -1;
        
        m = grid.size();
        n = grid[0].size();
        
        fireTime.resize(m, vector<int>(n, INT_MAX));
        updateFireTime(grid);
        
        int ans = -1;
        int low = 0;
        int high = m * n;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (isPossible(mid)) {
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }
        
        return ans == m*n ? 1e9 : ans;
    }
};
