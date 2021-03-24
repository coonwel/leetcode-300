class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int minLen = INT_MAX;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum >= s) {
                minLen = min(minLen, j-i+1);
                sum -= nums[i++]; // 从头部逐步移除
            }
        }
        return minLen != INT_MAX? minLen : 0;
    }
};
