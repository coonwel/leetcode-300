class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrace(nums, 0, res);
        return res;
    }

    void backtrace(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == nums.size()) {
            // base case
            res.push_back(nums);
            return;
        } else {
            // recursive case
            for (int i = start; i < nums.size(); i++) {
                std::swap(nums[start], nums[i]);
                backtrace(nums, start+1, res);
                std::swap(nums[start], nums[i]);
            }
        }
    }
};
