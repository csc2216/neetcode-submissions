class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);

        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }

        int n = numCourses;

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                n--;
            }
        }

        while (!q.empty()) {
            int p = q.front();
            q.pop();

            for (int c : adj[p]) {
                if (--indegree[c] == 0) {
                    q.push(c);
                    n--;
                }
            }
        }

        return n == 0;
    }
};
