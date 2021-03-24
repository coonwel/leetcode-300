class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (k < 0 || k > nums.size())
            return -1;

        int left = 0, right = nums.size()-1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == nums.size()-k) {
                return nums[pos];
            } else if (pos > nums.size()-k) {
                right = pos-1;
            } else {
                left = pos+1;
            }
        }
    }

    int partition(vector<int>& nums, int start, int end) {
        int temp = nums[start];
        int i = start, j = end;
        while (i < j) {
            while (i < j && nums[j] >= temp) j--;
            while (i < j && nums[i] <= temp) i++;

            std::swap(nums[i], nums[j]);
        }
        std::swap(nums[i], nums[start]);
        return i;
    }
};
