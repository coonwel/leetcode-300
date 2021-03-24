class Solution {
public:
    vector<vector<string>> partition(string& s) {
        vector<vector<string>> res;
        vector<string> out;
        backtrace(s, 0, out, res);
        return res;
    }

    void backtrace(const string& s, int start, string& out, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(out);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i) == false) continue;
            out.push_back(s.substr(start, i-start+1));
            backtrace(s, i+1, out, res);
            out.pop_back();
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right)
            if (s[left++] != s[right--]) return false;
        return true;
    }
};
