class Solution {
public:
    vector<int> tmps, index, res;
    vector<int> countSmaller(vector<int>& nums) {
        tmps.resize(nums.size());
        index.resize(nums.size());
        res.resize(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            index[i] = i;
            res[i] = 0;
        }
        mergesort(nums, 0, nums.size()-1);
        return res;
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        int s1 = left, s2 = mid+1, e1 = mid, e2 = right;
        int k = 0;
        while (s1 <= e1 && s2 <= e2) {
            if (nums[index[s1]] <= nums[index[s2]]) {
                tmps[k++] = index[s1++];
            } else {
                for (int i = s1; i <= mid; i++) {
                    ++res[index[i]];
                }
                tmps[k++] = index[s2++];
            }
        }
        while (s1 <= e1) {
            tmps[k++] = index[s1++];
        }
        while (s2 <= e2) {
            tmps[k++] = index[s2++];
        }

        for (int i = 0; i < k; i++) {
            index[i+left] = tmps[i];
        }
    }

    void mergesort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right-left)/2;
            mergesort(nums, left, mid);
            mergesort(nums, mid+1, right);
            merge(nums, left, mid, right);
        }
    }
};
