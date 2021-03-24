class Solution {
public:
    // 迭代方式
    double myPow(double x, double n) {
        double res = 1;
        while (n) {
            if (n%2 != 0) res *= x;
            x *= x;
            n /= 2;
        }
        return res;
    }

    // 递归方式
    double power(double x, double n) {
        if (n == 0) return 1;
        double v = power(x, n/2);
        if (n % 2 == 0)
            return v * v;
        else
            return v * v * x;
    }

    double myPow(double x, double n) {
        if (n < 0)
            return 1.0 / power(x, -n);
        else
            return power(x, n);
    }
};
