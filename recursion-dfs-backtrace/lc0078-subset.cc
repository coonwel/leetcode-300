class Solution {
public:
    vector<vector<int>> subset(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        backtrace(nums, 0, out, res);
        return res;
    }

    void backtrace(vector<int>& nums, int start, vector<int>& out, vector<vector<int>>& res) {
        res.push_back(out);
        for (int i = start; i < nums.size(); i++) {
            out.push_back(nums[i]);
            backtrace(nums, i+1, out, res);
            out.pop_back();
        }
    }
};
