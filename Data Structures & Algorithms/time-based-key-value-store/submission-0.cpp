class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()){
            return "";
        }

        auto &v = mp[key];

        int lo = 0;
        int hi = v.size() - 1;
        string ans = "";

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;

            if(v[mid].first <= timestamp){
                ans = v[mid].second;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
