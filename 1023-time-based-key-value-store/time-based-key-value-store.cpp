class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> m;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        if (m.count(key) == 0) {
            m[key] = vector<pair<string, int>>();
        }
        m[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        int low = 0;
        int high = m[key].size() - 1;
        string res = "";
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (m[key][mid].second <= timestamp) {
                res = m[key][mid].first;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */