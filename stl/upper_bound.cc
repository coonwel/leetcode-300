class Solution {
public:
    int upperbound(vector<int>& nums, int k) { // 求第一个大于k的位置
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] > k) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};