class KthLargest {
    bool full = true;
    priority_queue<int, vector<int>, greater<int>> kmin;

public:
    KthLargest(int k, vector<int>& nums) {
        int i = 0;
        while (i < k && i < nums.size()) {
            kmin.push(nums[i]);
            i++;
        }
        while (i < nums.size()) {
            kmin.push(nums[i]);
            kmin.pop();
            i++;
        }
        if (i < k) full = false;
    }
    
    int add(int val) {
        if (full) {
            kmin.push(val);
            kmin.pop();
            return kmin.top();
        } else {
            kmin.push(val);
            full = true;
            return kmin.top();
        }
    }
        
};
