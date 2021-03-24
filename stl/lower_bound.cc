class Solution {
public:
    int lowerbound(vector<int>& nums, int k) { // 求第一个大于等于k的位置
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] >= k) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};
