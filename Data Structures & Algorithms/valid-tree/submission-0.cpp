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

        int visitCount = 0;
        return !hasCycle(0, -1, visitCount, adj, visited) && visitCount == n;
    }

private:
    bool hasCycle(int u, int parent, int& visitCount, const vector<vector<int>>& adj, vector<bool>& visited) {
        visited[u] = 1; 
        visitCount++;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (visited[v]) return true; 
            
            if (hasCycle(v, u, visitCount, adj, visited)) return true;
        }

        return false;
    }
};
