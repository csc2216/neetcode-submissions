class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (char t : tasks) {
            counts[t]++;
        }

        priority_queue<int> heap;  // max_heap
        for (auto& [task, count] : counts) {
            heap.push(count);
        }

        queue<pair<int, int>> q;  // <count, time_to_release>, wait n cycles

        int cycles = 0;
        while (!heap.empty() || !q.empty()) {
            cycles++;

            if (!heap.empty()) {
                int cnt = heap.top() - 1;
                if (cnt > 0) {
                    q.push({cnt, cycles + n});
                }
                heap.pop();
            }

            if (!q.empty() && q.front().second == cycles) {
                heap.push(q.front().first);
                q.pop();
            }
        }

        return cycles;
    }
};
