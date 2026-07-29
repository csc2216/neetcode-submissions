class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int count = n;

        for (const auto& edge : edges) {
            int root0 = find(edge[0], parent);
            int root1 = find(edge[1], parent);

            if (root0 != root1) {
                parent[root0] = root1;
                count--;
            }
        }

        return count;
    }

private:
    int find(int i, vector<int>& parent) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i], parent);
    }
};
