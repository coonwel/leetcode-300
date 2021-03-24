

int threeSumCloest(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());

    int res = 0;
    int minGap = INT_MAX;
    for (int i = 0; i < nums.size()-2; i++) {
        int left = i+1, right = nums.size()-1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            int curGap = std::abs(sum - target);
            if (curGap < minGap) {
                res = sum;
                minGap = curGap;
            }

            if (sum < target) ++left;
            else --right;
        }
    }
    return res;
}


