class Solution {
   public:
    void dfs(int i, int n, vector<int> &vis, vector<vector<int>>&isConnected){
        if(i == n) return;

        if(vis[i]) return;

        // mark visited
        vis[i] = true;

        for(int v = 0; v < n; v++){
            if(isConnected[i][v] == 1 && !vis[v]){
                dfs(v, n, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, false);

        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, n, vis, isConnected);
                provinces++;
            }
        }

        return provinces;
    }
};