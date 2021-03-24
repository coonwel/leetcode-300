class Solution {
public:
    vector<int> tmps;
    void mergesort(vector<int>& nums) {
        tmps.resize(nums.size());
        mergesort(nums, 0, nums.size()-1);
    }

    void mergesort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right-left)/2;
            mergesort(nums, left, mid);
            mergesort(nums, mid+1, right);
            merge(nums, left, mid, right);
        }
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        int s1 = left, s2 = mid+1, e1 = mid, e2 = right;
        int k = 0;
        while (s1 <= e1 && s2 <= e2) {
            if (nums[s1] < nums[s2]) {
                tmps[k++] = nums[s1++];
            } else {
                tmps[k++] = nums[s2++];
            }
        }
        while (s1 <= e1) {
            tmps[k++] = nums[s1++];
        }
        while (s2 <= e2) {
            tmps[k++] = nums[s2++];
        }

        for (int i = 0; i < k; i++) {
            nums[left+i] = nums[i];
        }
    }
};
