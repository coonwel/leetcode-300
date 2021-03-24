class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        int index = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[index-1] != nums[i]) {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};
