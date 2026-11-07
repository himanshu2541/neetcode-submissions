class Solution {
   public:
    void bfs(int r, int c, int m, int n, vector<vector<char>> &grid, vector<vector<bool>> &vis){
        queue<pair<int, int>> q;
        q.push({r, c});
        vector<pair<int,int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(auto [dr, dc]: dirs){
                int nr = r + dr;
                int nc = c + dc;

                if(nr >= 0 && nc >= 0 && nr < m && nc < n && !vis[nr][nc] && grid[nr][nc] == '1'){
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                    cout << "nr: " << nr << " " << "nc: " << nc << "\n";
                }
            }
        }
    }

    void dfs(int r, int c, int m, int n, vector<vector<char>> &grid, vector<vector<bool>> &vis){
        // out of bound
        if(r < 0 || c < 0 || r >= m || c >= n) return;

        // if we got water
        if(grid[r][c] == '0') return;

        // if the piece of land is already visited
        if(vis[r][c]) return;

        // mark visited
        vis[r][c] = true;

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for(auto [dr, dc]: dirs){
            int nr = r + dr;
            int nc = c + dc;
            dfs(nr, nc, m, n, grid, vis);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int noOfIslands = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cout << i << j << "\n";
                    dfs(i, j, m, n, grid, vis);
                    noOfIslands++;
                }
            }
        }

        return noOfIslands;
    }
};
