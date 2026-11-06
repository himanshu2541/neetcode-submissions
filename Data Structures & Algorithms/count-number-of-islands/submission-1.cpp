class DSU {
    vector<int> parent, sz;

   public:
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x]) return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;
        if (sz[pu] < sz[pv]) swap(pu, pv);

        parent[pv] = pu;
        sz[pu] += sz[pv];
    }

    bool isConnected(int u, int v) { return find(u) == find(v); }
};

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        DSU ds(m * n);

        int islands = 0;

        // right and down dirs
        int dr[] = {0, 1};
        int dc[] = {1, 0};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }

                islands++;

                int node = i * n + j;

                for (int k = 0; k < 2; k++) {
                    int nr = i + dr[k];
                    int nc = j + dc[k];

                    if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == '1') {
                        int adjNode = nr * n + nc;
                        if (!ds.isConnected(node, adjNode)) {
                            ds.unite(node, adjNode);
                            islands--;
                        }
                    }
                }
            }
        }

        return islands;
    }
};
