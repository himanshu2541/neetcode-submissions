class DSU{
    vector<int> parent, sz;
    public:
        DSU(int n){
            // 0 based indexing
            parent.resize(n);
            sz.assign(n, 1);

            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }

        int find(int x){
            if(x == parent[x]) return x;

            return parent[x] = find(parent[x]);
        }

        void unite(int u, int v){
            int pu = find(u);
            int pv = find(v);

            if(pu == pv) return;

            if(sz[pu] < sz[pv]) swap(pu, pv);

            parent[pv] = pu;
            sz[pu] += sz[pv];
        }

        bool isConnected(int u, int v){
            return find(u) == find(v);
        }

        int countUltimateParents(){
            int count = 0;
            for(int i = 0; i < parent.size(); i++){
                if(parent[i] == i) count++;
            }

            return count;
        }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();

        DSU ds(n);
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && isConnected[i][j]){
                    if(ds.isConnected(i,j)) continue;
                    ds.unite(i, j);

                    if(count == n - 1){
                        break;
                    }
                }
            }
        }

        return ds.countUltimateParents();
    }
};