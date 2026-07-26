class MedianFinder {
    bool odd;  // #int in heap
    priority_queue<int> lowHeap;  // maxHeap
    priority_queue<int, vector<int>, greater<int>> highHeap;  // minHeap

public:
    MedianFinder() : odd(false) {
        
    }
    
    void addNum(int num) {
        if (lowHeap.empty()) {
            lowHeap.push(num);
            odd = true;

        } else if (highHeap.empty()) {
            int l = lowHeap.top();
            if (num < l) {
                lowHeap.pop();
                lowHeap.push(num);
                highHeap.push(l);
            } else {
                highHeap.push(num);
            }
            odd = false;

        } else {
            int l = lowHeap.top();
            int h = highHeap.top();

            if (odd) {
                if (num < l) {
                    lowHeap.pop();
                    lowHeap.push(num);
                    highHeap.push(l);
                } else {
                    highHeap.push(num);
                }
                odd = false;
            } else {
                if (num > h) {
                    highHeap.pop();
                    highHeap.push(num);
                    lowHeap.push(h);
                } else {
                    lowHeap.push(num);
                }
                odd = true;
            }
        }
    }
    
    double findMedian() {
        if (odd) {
            return lowHeap.top();
        } else {
            return (lowHeap.top() + highHeap.top()) / 2.0; 
        }   
    }
};
