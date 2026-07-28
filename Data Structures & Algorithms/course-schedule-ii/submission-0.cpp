class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        vector<int> order;

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int p = q.front();
            q.pop();

            order.push_back(p);

            for (int c : adj[p]) {
                if (--indegree[c] == 0) {
                    q.push(c);
                }
            }
        }

        if (order.size() == numCourses) return order;
        else return {};
    }
};
