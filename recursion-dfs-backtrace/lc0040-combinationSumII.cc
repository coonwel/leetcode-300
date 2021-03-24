class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        backtrace(candidates, target, 0, 0, {}, res);
        return res;
    }

    void backtrace(vector<int>& candidates, int target, int start, int sum, vector<int>&& path, vector<vector<int>>& res) {
        if (sum == target) res.push_back(path);
        if (sum >= target) return; // 剪枝
        for (int i = start; i < candidates.size(); i++) {
            if (sum+candidates[i] > target) return; // 二次剪枝
            if (i>start && candidates[i] == candidates[i-1]) continue; // 去重

            path.push_back(candidates[i]);
            backtrace(candidates, target, i+1, sum+candidates[i], path, res);
            path.pop_back();
        }
    }
};
