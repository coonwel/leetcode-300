class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size()-1);
        return nums;
    }

    void quicksort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int i = left, j = right;
            while (i < j) {
                while (i < j && nums[j] >= nums[left])
                    j--;
                while (i < j && nums[i] <= nums[left])
                    i++;
                std::swap(nums[i], nums[j]);
            }
            std::swap(nums[i], nums[left]);

            quicksort(nums, left, i-1);
            quicksort(nums, i+1, right);
            // pivot = partition(nums, left, right);
            // quicksort(nums, left, pivot-1);
            // quicksort(nums, pivot+1, right);
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int i = left, j = right;
        while (i < j) {
            while (i < j && nums[j] >= nums[left])
                j--;
            while (i < j && nums[i] <= nums[left])
                i++;
            std::swap(nums[i], nums[j]);
        }
        std::swap(nums[i], nums[left]);
        return i;
    }
};
