class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int idx = 0; idx < intervals.size(); idx++) {
            int start = intervals[idx][0];
            int end   = intervals[idx][1];
            while (idx+1<intervals.size() && end >= intervals[idx+1][0]) {
                end = std::max(end, intervals[idx+1][1]);
                idx++;
            }
            res.push_back({start, end});
        }
        return res;
    }
};
