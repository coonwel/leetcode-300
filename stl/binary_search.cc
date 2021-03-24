class Solution {
public:
    int binary_search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};