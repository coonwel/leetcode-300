class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        while (i>=0 || j>=0 || carry>0) {
            int sum = (i>=0?a[i--]-'0':0) + (j>=0?b[j--]-'0':0) + carry;
            carry = sum/2;
            res += '0' + sum%2;
        }
        return string(res.rbegin(), res.rend());
    }
};
