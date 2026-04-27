class TimeMap {
public:
    map<string, vector<pair<int, string>>> mmap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mmap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> vec = mmap[key];
        
        return bs(vec, timestamp);
    }

    string bs(vector<pair<int, string>>& vec, int timestamp) {
        if (vec.size() == 0) return "";
        string res = "";
        int l=0, r = vec.size() -1 , mid;

        while (l <= r) {
            mid = (l+r) / 2;

            if (vec[mid].first <= timestamp) {
                res = vec[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};
