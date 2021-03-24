class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int start = newInterval[0];
        int end   = newInterval[1];
        size_t pos = 0;
        for (size_t idx = 0; idx < intervals.size(); idx++) {
            if (end < intervals[idx][0]) {
                res.push_back(intervals[idx]);
                pos++;
            } else if (start > intervals[idx][1]) {
                res.push_back(intervals[idx]);
            } else {
                start = std::min(start, intervals[idx][0]);
                end = std::max(end, intervals[idx][1]);
            }
        }
        res.insert(res.begin() + pos, {start, end});
        return res;
    }
};
