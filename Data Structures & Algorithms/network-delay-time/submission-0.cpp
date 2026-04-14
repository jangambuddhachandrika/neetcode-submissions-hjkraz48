class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build adjacency list
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto &t : times) {
            adj[t[0]].push_back({t[1], t[2]}); // u -> (v, weight)
        }

        // Step 2: Min heap {time, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        
        // Step 3: Distance array
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        pq.push({0, k});

        // Step 4: Dijkstra
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            // Skip outdated entries
            if (time > dist[node]) continue;

            for (auto &[neighbor, wt] : adj[node]) {
                if (dist[neighbor] > time + wt) {
                    dist[neighbor] = time + wt;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        // Step 5: Get max delay
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
