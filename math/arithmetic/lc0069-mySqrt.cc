class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int left = 1, right = x/2;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (x / mid >= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left-1;
    }
};
