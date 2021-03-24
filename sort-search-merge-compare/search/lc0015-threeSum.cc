class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 3 || nums[0] > 0 || nums[nums.size()-1]<0) {
            return res;
        }

        for (int idx=0; idx<nums.size()-2; idx++) {
            if (nums[idx] > 0) break;
            if (idx>0 && nums[idx]==nums[idx-1]) continue;

            int left = idx+1, right=nums.size()-1;
            while (left < right) {
                if (nums[left]+nums[right]+nums[idx] == 0) {
                    res.push_back({nums[left], nums[right], nums[idx]});

                    while (left < right && nums[left] == nums[left+1])
                        left++;
                    while (left < right && nums[right] == nums[right-1])
                        right--;
                    left++;
                    right--;
                } else if (nums[left]+nums[right]+nums[idx] < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return res;
    }
};
