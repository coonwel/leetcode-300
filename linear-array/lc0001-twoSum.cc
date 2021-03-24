class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mymap;
        for (int idx = 0; idx < nums.size(); idx++) {
            if (mymap.count(target - nums[idx])) {
                return {mymap[nums[idx]], idx};
            }

            mymap[nums[idx]] = idx;
        }
        return {};
    }
};
