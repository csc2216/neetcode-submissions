class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> heap;  // <dist, index>, max_heap
        int i = 0;
        while (i < k) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            heap.push({dist, i});
            i++;
        }
        while (i < points.size()) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (dist < heap.top().first) {
                heap.pop();
                heap.push({dist, i});
            }
            i++;
        }

        vector<vector<int>> result;
        while (!heap.empty()) {
            int i = heap.top().second;
            result.push_back({points[i][0], points[i][1]});
            heap.pop();
        }
        return result;
    }
};
