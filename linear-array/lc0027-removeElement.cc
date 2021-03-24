class Solution {
public:
    int removeElement(vector<int>& nums, int target) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target != nums[i]) {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};
