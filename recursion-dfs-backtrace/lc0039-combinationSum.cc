class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        backtrace(candidates, target, 0, path, res);
        return res;
    }

    void backtrace(vector<int>& candidates, int target, int start, int sum, vector<int>& path, vector<vector<int>>& res) {
        if (sum == target) res.push_back(path);
        if (sum >= target) return;
        for (int i = start; i < candidates.size(); i++) {
            if (sum+candidates[i] > target) return; // 二次剪枝

            path.push_back(nums[i]);
            backtrace(candidates, target, i, sum+candidates[i], path, res);
            path.pop_back();
        }
    }
};
