class Solution {
public:
    int findMinInRotatedArray(vector<int>& nums) {
        if (nums.front() < nums.back()) return nums.front();

        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] < nums[right]) // 小于或者小于等于均可
                right = mid;
            else
                left = mid+1;
        }
        return nums[left];
    }
};
