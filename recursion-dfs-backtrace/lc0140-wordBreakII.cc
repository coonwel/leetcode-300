class Solution {
public:
    // 此方法对应s长度远大于wordDict的长度
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return backtrace(s, wordDict);
    }

    unordered_map<string, vector<string>> memo;
    vector<string> backtrace(string s, vector<string>& wordDict) {
        if (memo.count(s)) return memo[s];
        if (s.empty()) return {""};
        vector<string> res;
        for (string word : wordDict) {
            if (s.substr(0, word.size()) != word) continue;
            vector<string> temp = wordBreak(s.substr(word.size()), wordDict);
            for (string str : temp) {
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        return memo[s] = res;
    }


    // 此方法对应wordDict长度远大于s的长度
    unordered_set<string> wordMap;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto word : wordDict) {
            wordMap.insert(word);
        }

        vector<string> out;
        vector<vector<string>> vecs;
        backtrace(s, 0, out, vecs);

        vector<string> res;
        for (auto v : vecs) {
            string tmp;
            for (int i = 0; i < v.size(); i++)
                tmp += v[i] +  (i == v.size()-1 ? "" : " ");
            res.push_back(tmp);
        }

        return res;
    }

    void backtrace(string s, int start, vector<string>& out, vector<vector<string>>& res) {
        if (s.size() == start) {
            res.push_back(out);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if ( wordMap.count(s.substr(start, i-start+1)) == false ) continue;
            out.push_back( s.substr(start, i-start+1) );
            backtrace(s, i+1, out, res);
            out.pop_back();
        }
    }
};
