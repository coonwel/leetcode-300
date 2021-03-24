

vector<int> plusOne(vector<int>& nums) {
    int carry = 1;
    int i = nums.size()-1;
    vector<int> res;
    while (i >=0 || carry > 0) {
        int sum = (i>=0 ? nums[i--] : 0) + carry;
        res.insert(res.begin(), sum%10);
        carry = sum/10;
    }
    return res;
}
