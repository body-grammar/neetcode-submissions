class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> timemap;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(timemap.find(key) == timemap.end()) return "";

        vector<pair<string, int>>& history = timemap[key];

        int start = 0;
        int end = history.size() - 1;
        int best = -1;

        while(start <= end)
        {
            int mid = start + ((end - start) / 2);

            if(history[mid].second == timestamp)
            {
                return history[mid].first;
            } else if(history[mid].second > timestamp)
            {
                end = mid - 1;
            } else 
            {
                best = mid;
                start = mid + 1;
            }
        }

        if(best == -1) return "";

        return history[best].first;
    }
};
