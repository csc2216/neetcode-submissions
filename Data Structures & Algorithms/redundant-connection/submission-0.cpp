class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (const auto& edge : edges) {
            int root0 = find(edge[0], parent);
            int root1 = find(edge[1], parent);

            if (root0 == root1) {
                return edge;
            } else {
                parent[root0] = root1;
            }
        }

        return {};
    }

private:
    int find(int i, vector<int>& parent) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i], parent);
    }
};
