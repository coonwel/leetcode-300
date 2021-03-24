class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        if (target > nums[size - 1]) return -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;  
    }

    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> startVec;
        unordered_map<int, int> indexMap;

        for (int idx = 0; idx < intervals.size(); idx++) {
            indexMap[intervals[idx][0]] = idx;
            startVec.push_back(intervals[idx][0]);
        }
        std::sort(startVec.begin(), startVec.end());

        vector<int> res(intervals.size(), -1);
        for (int idx = 0; idx < intervals.size(); idx++) {
            int pos = lower_bound(startVec, intervals[idx][1]);
            res[i] = (pos >= 0) ? indexMap[startVec[pos]] : -1;
        }
        return res;
    }
};
