class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> cars;  /* <position, time_need> */

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], (float)(target -  position[i]) / speed[i]});
        }
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        float time_need = cars[0].second;
        int result = 1;
        for (int i = 1; i < position.size(); i++) {
            if (cars[i].second > time_need) {
                result += 1;
                time_need = cars[i].second;
            }
        }
        return result;
    }
};
