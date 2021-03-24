class Solution {
public:
    vector<string> board = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) { 
        vector<string> res;
        string out;
        backtrace(digits, 0, out, res);
        return res;
    }

    void backtrace(string digits, int pos, string out, vector<string>& res) {
        if (pos == digits.size()) {
            res.push_back(out);
        } else {
            string str = board[ digits[pos] - '0' ];
            for (int i = 0; i < str.size(); i++) {
                backtrace(digits, pos + 1, out + str[i], res);
            }
        }
    }
};

