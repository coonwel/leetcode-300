class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        int res = 0;
        int lastIdx = 0;
        for (int idx = 1; idx < intervals.size(); idx++) {
            if (intervals[lastIdx][1] > intervals[idx][0]) {
                // 只有大于end才更新idx.
                if (intervals[lastIdx][1] > intervals[idx][1]) {
                    lastIdx = idx;
                }
                res++;
            } else {
                lastIdx = idx;
            }
        }
        return res;
    }
};
