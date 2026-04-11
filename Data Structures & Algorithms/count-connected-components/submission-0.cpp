class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        
        // Build graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> visited(n, 0);
        int components = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                components++;
                
                queue<int> q;
                q.push(i);
                visited[i] = 1;
                
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    
                    for (int nei : adj[node]) {
                        if (!visited[nei]) {
                            visited[nei] = 1;
                            q.push(nei);
                        }
                    }
                }
            }
        }
        
        return components;
    }
};
