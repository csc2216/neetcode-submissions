class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if  (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);
        for(const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;
        int visitCount = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visitCount++;

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        return visitCount == n;
    }
};
