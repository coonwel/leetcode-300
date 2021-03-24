class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % k == 0) return false;
        int target = sum / k;
        vector<bool> visited(nums.size(), false);
        return backtrace(nums, k, target, 0, 0, visited);
    }

    bool backtrace(vector<int>& nums, int k, int target, int start, int curSum, vector<bool>& visited) {
        if (k == 1) return true; // 全部收入
        if (curSum == target) {
            return backtrace(nums, k-1, target, 0/*new start*/, 0/*new sum*/, visited);
        }
        for (int i = start; i < nums.size(); i++) {
            if (visited[i] == true) continue;
            visited[i] = true;
            if ( backtrace(nums, k, target, i+1, curSum+nums[i], visited) ) return true;
            visited[i] = false;
        }
        return false;
    }
};
