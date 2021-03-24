class Solution {
public:
    vector<string> restoreIpAddresses(const string& s) {
        vector<string> res;
        vector<string> ip;
        backtrace(s, 0, ip, res);
        return res;
    }

    void backtrace(const string& s, int start, vector<string>& ip, vector<string>& res) {
        if (ip.size() == 4 && start == s.size()) {
            res.push_back( ip[0]+"."+ip[1]+"."+ip[2]+"."+ip[3] );
            return;
        }

        if (s.size() - start > (4 - ip.size()) *3) return;
        if (s.size() - start < (4 - ip.size())) return;

        int num = 0;
        for (int i = start; i < start+3; i++) {
            num = num*10 + (s[i]-'0');
            if (num > 255) break;

            ip.push_back( s.substr(start, i-start+1) );
            backtrace(s, i+1, out, res);
            ip.pop_back();

            if (num == 0) break;
        }
    }
};
