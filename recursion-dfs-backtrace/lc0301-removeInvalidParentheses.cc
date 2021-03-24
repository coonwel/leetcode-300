class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int count1 = 0, count2 = 0;
        for (char c : s) {
            count1 += (c == '(');
            if (count1 == 0) count2 += (c == ')');
            else count1 -= (c == ')');
        }

        backtrace(s, 0, count1, count2, res);
        return res;
    }

    void backtrace(string s, int start, int count1, int count2, vector<string>& res) {
        if (count1 == 0 && count2 == 0) {
            if (isValidParentheses(s)) res.push_back(s);
            return;
        }

        for (int i = start; i < s.size(); i++) {
            if (i != start && s[i] == s[i-1]) continue;
            string t = s.substr(0, i) + s.substr(i + 1); // 代表删除了该字符
            if (count1 > 0 && s[i] == '(') backtrace(t, i, count1 - 1, count2, res);
            if (count2 > 0 && s[i] == ')') backtrace(t, i, count1, count2 - 1, res);
        }
    }

    bool isValidParentheses(string t) {
        int count = 0;
        for (auto c : t) {
            if (c == '(') ++count;
            else if (c == ')' && --count < 0) return false;
        }
        return (count == 0);
    }
};
