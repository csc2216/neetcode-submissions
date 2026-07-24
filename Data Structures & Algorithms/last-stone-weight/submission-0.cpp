class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int length = stones.size();
        priority_queue<int, vector<int>> heap;  // max_heap
        for (int i = 0; i < length; i++) {
            heap.push(stones[i]);
        }

        while (length > 1) {
            int a = heap.top(); heap.pop();
            int b = heap.top(); heap.pop();
            if (a > b) {
                heap.push(a - b);
                length--;
            } else {
                length -= 2;
            }
        }

        if (heap.empty()) return 0;
        else return heap.top();
    }
};
