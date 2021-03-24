class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(),-1);
        stack<int> mystack;
        int n = nums.size();
        for (int i = 0; i < 2*n; i++) {
            while (!mystack.empty() && nums[mystack.top()] < nums[i%n]) {
                res[mystack.top()] = nums[i%n];
                mystack.pop();
            }

            if (i < nums.size()) {
                mystack.push(i);
            }
        }
        return res;
    }
};
