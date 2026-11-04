class Solution {
   public:
    void bfs(int i, int n, vector<int>& vis, vector<vector<int>>& isConnected) {
        queue<int> q;
        q.push(i);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < n; v++) {
                if (isConnected[u][v] == 1 && !vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, false);

        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                bfs(i, n, vis, isConnected);
                provinces++;
            }
        }

        return provinces;
    }
};