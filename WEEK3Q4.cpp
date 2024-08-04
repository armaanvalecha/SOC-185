#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class TimeMap {
private:
    unordered_map<string, map<int, string>> count;

    string search(const vector<pair<int, string>>& arr, int timestamp) {
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (arr[mid].first == timestamp) {
                return arr[mid].second;
            } else if (arr[mid].first > timestamp) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return (end >= 0 && end < arr.size()) ? arr[end].second : "";
    }

public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        count[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (count.find(key) == count.end()) {
            return "";
        }
        
        auto& tmap = count[key];
        auto it = tmap.lower_bound(timestamp);
        if (it != tmap.end() && it->first == timestamp) {
            return it->second;
        }

        if (it == tmap.begin()) {
            return "";
        }

        --it;
        return it->second;
    }
};

int main() {
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);
    cout << timeMap.get("foo", 1) << endl; // Output: "bar"
    cout << timeMap.get("foo", 3) << endl; // Output: "bar"
    timeMap.set("foo", "bar2", 4);
    cout << timeMap.get("foo", 4) << endl; // Output: "bar2"
    cout << timeMap.get("foo", 5) << endl; // Output: "bar2"
    return 0;
}
