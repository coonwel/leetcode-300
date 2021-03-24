class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        bool res = false; 
        vector<double> dnums(nums.begin(), nums.end());
        backtrace(dnums, res);
        return res;
    }

    void getAllCases(int p, int q, vector<double>& tmps) {
        tmps.push_back(p+q);
        tmps.push_back(p-q);
        tmps.push_back(q-p);
        tmps.push_back(p*q);
        if (q > 0.001) tmps.push_back(p/q);
        if (p > 0.001) tmps.push_back(q/p);
    }

    void backtrace(vector<double>& nums, bool& res) {
        if (res) return;
        if (nums.size() == 1) {
            if (std::abs(nums.back() - 24) < 0.001) res = true;
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                double p = nums[i], q = nums[j];
                vector<int> tmps;
                getAllCases(p, q, tmps);
                nums.erase(nums.begin()+i);
                nums.erase(nums.begin()+j);

                for (int k = 0; k < tmps.size(); k++) {
                    nums.push_back(tmps[k]);
                    backtrace(nums, res);
                    nums.pop_back();
                }

                nums.insert(nums.begin()+j, q);
                nums.insert(nums.begin()+i, p);
            }
        }
    }
};
