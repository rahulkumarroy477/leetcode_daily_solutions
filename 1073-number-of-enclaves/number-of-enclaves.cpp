class Solution {
private:
    int m, n;
    vector<vector<bool>> vis;

    bool isValid(int x, int y) {
        return (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]);
    }
    
    vector<pair<int, int>> directions{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    
    int dfs(int x, int y, vector<vector<int>>& grid) {
        vis[x][y] = true;
        int count = 1; // Start counting with the current cell

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;

            if (isValid(nx, ny) && grid[nx][ny] == 1) {
                count += dfs(nx, ny, grid);
            }
        }

        return count;
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vis.resize(m, vector<bool>(n, false));

        // Mark boundary-connected land cells
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && 
                    grid[i][j] == 1 && !vis[i][j]) {
                    dfs(i, j, grid);
                }
            }
        }

        int enclaveCount = 0;
        // Count land cells not connected to the boundary
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    enclaveCount += dfs(i, j, grid);
                }
            }
        }

        return enclaveCount;
    }
};
