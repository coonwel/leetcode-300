class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            while (left < right && nums[left] == nums[left+1])
                left++;
            while (left < right && nums[right] == nums[right-1])
                right--;

            int mid = left + (right - left)/2;
            if (nums[mid] == target) return true;

            if (nums[mid] < nums[right]) {
                if (target <= nums[right] && nums[mid] <= target) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            } else {
                if (target <= nums[mid] && nums[left] <= target) {
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }
        }
        return false;
    }
};
