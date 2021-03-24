class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        for (int i = 0; i < n; i++) {
            int bitone = 1<<i;
            for (int j = res.size()-1; j >= 0; j--) {
                res.push_back( bitone | res[j] );
            }
        }
        return res;
    }
};
