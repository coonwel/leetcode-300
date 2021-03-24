class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty() || s.size() < words.size()*words[0].size()) return {};

        size_t ssize = s.size(), wlen = words.size(), wsize = words[0].size();
        vector<int> res;
        unordered_map<string, int> exptected;
        for (auto word : words) {
            exptected[word]++;
        }

        for (int i = 0, j = 0; i <= s.size() - wlen*wsize; i++) {
            unordered_map<string, int> matched;
            for (j = 0; j < wlen; j++) {
                string str = s.substr(i+j*wsize, wsize);
                matched[str]++;
                if (matched[str] > exptected[str]) break;
            }
            if (j == wlen) res.push_back(i);
        }
        return res;

    }
};
