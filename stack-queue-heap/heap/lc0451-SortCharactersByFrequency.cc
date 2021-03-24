class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        unordered_map<char, int> mymap;
        auto cmp=[](pair<int,char>& a, pair<int, char>& b) {
            return a.first < b.first;
        };
        priority_queue<pair<int, char>, vector<pair<int, char>>, decltype(cmp)> myqueue(cmp);
        for (char c : s) {
            ++mymap[c];
        }
        for (auto it = mymap.begin(); it != mymap.end(); it++) {
            myqueue.push(make_pair(it->second, it->first));
        }
        while (!myqueue.empty()) {
            auto tmp = myqueue.top();
            myqueue.pop();
            res += string(tmp.first, tmp.second);
        }
        return res;
    }
};