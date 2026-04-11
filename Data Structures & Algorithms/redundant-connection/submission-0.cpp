class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);
        
        // initialize parent
        for (int i = 0; i <= n; i++)
            parent[i] = i;
        
        // find with path compression (iterative)
        auto find = [&](int x) {
            while (x != parent[x]) {
                parent[x] = parent[parent[x]]; // path compression
                x = parent[x];
            }
            return x;
        };
        
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            
            int pu = find(u);
            int pv = find(v);
            
            if (pu == pv) {
                return e; // cycle found
            }
            
            // union by rank
            if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
        
        return {};
    }
};
