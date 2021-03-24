class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left  = lower_bound(nums, 0, nums.size(), target);
        if (left == nums.size() || nums[left] != target) return {-1,-1};
        int right = upper_bound(nums, left, nums.size(), target);
        return {left, right-1};
    }

    int lower_bound(vector<int>& nums, int left, int right, int target) {
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }

    int upper_bound(vector<int>& nums, int left, int right, int target) {
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
}
