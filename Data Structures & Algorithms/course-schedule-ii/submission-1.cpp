class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        // 0: Unvisited, 1: Visiting, 2: Visited
        vector<int> state(numCourses, 0);

        vector<int> order;

        for (int i = 0; i < numCourses; ++i) {
            if (state[i] == 0) {
                if (hasCycle(i, adj, state, order)) {
                    return {}; 
                }
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }

private:
    bool hasCycle(int u, const vector<vector<int>>& adj, vector<int>& state, vector<int>& order) {
        state[u] = 1; 

        for (int v : adj[u]) {
            if (state[v] == 1) {
                return true; 
            }
            if (state[v] == 0) {
                if (hasCycle(v, adj, state, order)) {
                    return true;
                }
            }
        }

        state[u] = 2;
        order.push_back(u); 
        return false;
    }
};
