class Solution {
public:
    vector<vector<string>> subsetII(vector<int>& nums) {
        vector<vector<string>> res;
        vector<string> out;
        backtrace(nums, 0, out, res);
        return res;
    }

    void backtrace(vector<int>& nums, int start, vector<string>& out, vector<vector<string>>& res) {
        res.push_back(out);

        for (int i = start; i < nums.size(); i++) {
            out.push_back(nums[i]);
            backtrace(nums, i+1, out, res);
            out.pop_back();
            while (i+1<nums.size() && nums[i+1] == nums[i]) i++;
        }
    }
};
