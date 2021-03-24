

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int res = 0, j = 0, last = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            while (j < i && nums[i] - nums[j] > k) {
                j++;
            }
            if (j < i && nums[j] != last && nums[i] - nums[j] == k) {
                ++res;
                last = nums[j];
            }
        }
        return res;
    }
};



