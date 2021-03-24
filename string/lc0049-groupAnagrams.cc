class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mymap;
        for (auto str : strs) {
            vector<int> cnt(26);
            for (char c :str) {
                ++cnt[c - 'a'];
            }
            string key;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] == 0) continue;
                key += string(1, i+'a') + to_string(cnt[i]);
            }
            mymap[key].push_back(str);
        }

        for (auto pr : mymap) {
            res.push_back(pr.second);
        }

        return res;
    }
};
