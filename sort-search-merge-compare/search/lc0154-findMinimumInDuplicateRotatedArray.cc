class Solution {
public:
    int findMinInRotatedArray(vector<int>& nums) {
        if (nums.front() < nums.back()) return nums.front();

        int left = 0, right = nums.size()-1;
        while (left < right) {
            while (left < right && nums[right] == nums[right-1])
                right--;
            while (left < right && nums[left] == nums[left+1])
                left++;

            int mid = left + (right - left)/2;
            if (nums[mid] < nums[right])
                right = mid;
            else
                left = mid+1;
        }

        return nums[left];
    }
};
