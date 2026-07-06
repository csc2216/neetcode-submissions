class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> wait_big;  /* <index, temp> */ 
        vector<int> result(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!wait_big.empty() && temperatures[i] > wait_big.top().second) {
                result[wait_big.top().first] = i - wait_big.top().first;
                wait_big.pop();
            }
            wait_big.push({i, temperatures[i]});
        }
        return result;    
    }
};
