class Solution {
public:
    void nextPermutation(string& nums) {
        for (int i = nums.size()-1; i > 0; i--) {
            if (nums[i-1] < nums[i]) {
                for (int j = nums.size()-1; j >= i; j--) {
                    if (nums[i-1] < nums[j]) {
                        std::swap(nums[i-1], nums[j]);
                        std::reverse(nums.begin() + i, nums.end());
                        return;
                    }
                }
            }
        }
        std::reverse(nums.begin(), nums.end());
        return;
    }

    string getKthPermutation(int n, int k) {
        string str(n , '0');
        for (int i = 0; i < n; i++) {
            str[i] += i+1;
        }
        for (int i = 0; i < k-1; i++) {
            nextPermutation(str);
        }
        return str;
    }
};
