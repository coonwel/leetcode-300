class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0, j = height.size()-1;
        while (i < j) {
            int h = std::min(height[i], height[j]);
            res = std::max(res, h*(j-i));
            while (i < j && h == height[i]) i++;
            while (i < j && h == height[j]) j--;
        }
        return res;
    }
};
