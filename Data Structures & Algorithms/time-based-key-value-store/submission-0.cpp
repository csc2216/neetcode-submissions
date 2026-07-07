class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> keys;
public:
    TimeMap() {
    
    }
    
    void set(string key, string value, int timestamp) {
        keys[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>& values = keys[key];
        int l = 0;
        int r = values.size() - 1;
        int mid;
        string result = "";

        while (l <= r) {
            mid = l + (r - l) / 2;
            if (values[mid].second == timestamp) return values[mid].first;
            else if (values[mid].second > timestamp) r = mid - 1;
            else if (values[mid].second < timestamp) {
                result = values[mid].first;
                l = mid + 1;
            }
        }
        return result;
    }
};
