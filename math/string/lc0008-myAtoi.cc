class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) return 0;

        int i = 0;
        while (s[i] == ' ' && i < s.size()) i++;

        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i++] == '-') ? -1 : 1;
        }

        long res = 0;
        while (i < s.size()) {
            if (s[i]-'0' < 0 || s[i]-'0' > 9) {
                break;
            } else {
                res = res*10 + (s[i++] - '0');
                if (res > INT_MAX) return (sign == -1) ? INT_MIN : INT_MAX;
            }
        }
        return res * sign;
    }
};
