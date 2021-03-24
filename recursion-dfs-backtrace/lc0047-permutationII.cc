class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        backtrace(nums, 0, res); 
        return res;
    }

    void backtrace(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        } else {
            for (int i = start; i < nums.size(); i++) {
                int j = i-1;
                while (j >= start && nums[i] != nums[j]) j--;
                if (j != start-1) continue; // 说明存在重复项
                std::swap(nums[start], nums[i]);
                backtrace(nums, start+1, res);
                std::swap(nums[start], nums[i]);
            }
        }
    }
};
