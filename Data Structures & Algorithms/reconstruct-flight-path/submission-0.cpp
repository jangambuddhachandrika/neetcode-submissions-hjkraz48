class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
        for (auto& t : tickets) {
            graph[t[0]].push(t[1]);
        }

        vector<string> result;
        stack<string> st;
        st.push("JFK");

        while (!st.empty()) {
            string node = st.top();
            if (!graph[node].empty()) {
                string next = graph[node].top();
                graph[node].pop();
                st.push(next);
            } 
            else {
                result.push_back(node);
                st.pop();
            }
        }

        reverse(result.begin(), result.end());
        return result;
        
    }
};
