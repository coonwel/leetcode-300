class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> multi(num1.size() + num2.size(), 0);
        for (int i = num1.size()-1; i >= 0; i--) {
            for (int j = num2.size()-1; j>=0; j--) {
                int prod = (num1[i] - '0')* (num2[j] - '0') + multi[i+j+1];
                multi[i+j]  += prod/10;
                multi[i+j+1] = prod%10;
            }
        }

        while (!multi.empty() && multi.front() == 0) {
            multi.erase(multi.begin());
        }

        string res;
        for (auto num : multi) {
            res += (num + '0');
        }
        return res.empty() ? "0" : res;
    }
};
